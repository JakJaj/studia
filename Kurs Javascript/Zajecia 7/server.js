import express, { json } from 'express';
import WebSocket, {WebSocketServer} from 'ws';
import fs from 'fs';
import makeDb from './database.js';

const app = express();
app.use(express.static('public'));

let jsonData = await getData();
let jsonKeys = await getKeys();


const wss = new WebSocketServer({port:8080});

wss.on('connection', (ws, res)=>{
    ws.on('message', data =>{
        let newData = JSON.parse(data.toString());

        console.log(newData);

        let dataToUpdataIndex = JSONDifferenceIndex(jsonData.data, newData.data);
        let keyToRemoveIndex = JSONDifferenceIndex(jsonKeys.keys, newData.keys);

        removeUsedCode(keyToRemoveIndex);
        updateVotes(dataToUpdataIndex);
        addVoteCodeData(jsonKeys.keys[keyToRemoveIndex], dataToUpdataIndex);

        newData.data.forEach((d, index) => {
            jsonData.data[index] = +d;
        });

        jsonKeys.keys = newData.keys;
        
        let date = new Date().toLocaleDateString();
        let time = new Date().toLocaleTimeString();
        let datetime = (date + ' ' + time).toString();

        wss.clients.forEach(c=>{
            if(c.readyState === WebSocket.OPEN){
                c.send(JSON.stringify({time:datetime, message:`Updated data`, data:jsonData.data, keys:jsonKeys.keys}))
            }
        });
    });

    let date = new Date().toLocaleDateString();
    let time = new Date().toLocaleTimeString();
    let datetime = (date + ' ' + time).toString();
    ws.send(JSON.stringify({time:datetime, message:`Welcome from the Server`, data:jsonData.data, keys:jsonKeys.keys}));
});

async function getKeys() {
    let keys = [];
    const db = makeDb();
    try {
        
        var rows = await db.pool.query("SELECT * FROM glosowanie.codes");
        
        for (let i = 0, len = rows.length; i < len; i++) {
            keys.push(rows[i].code);
        }
        
    } catch (err) {
        console.log(err);
    } finally {
		db.pool.end();
	}
    return {"keys": keys};
}

async function getData() {
    let data = [];
    const db = makeDb();
    try {
        
        var rows = await db.pool.query("SELECT * FROM glosowanie.data");
        
        for (let i = 0, len = rows.length; i < len; i++) {
            data.push(rows[i].votes);
        }
        
    } catch (err) {
        console.log(err);
    }
    finally{
        db.pool.end();
    }
    return {"data": data};
}

function JSONDifferenceIndex(obj1, obj2) {
    for (let i = 0 ; i < obj1.length; i++){
        if(obj1[i] !== obj2[i]){
            return i;
        }
    }
}

async function removeUsedCode(index) {
    console.log(`Removing code: ${index}`);
    let code = jsonKeys.keys[index];
    const db = makeDb();
    try {
        var rows = await db.pool.query(`DELETE FROM glosowanie.codes WHERE code = '${code}'`);
        
    } catch (err) {
        console.log(err);
    } finally {
        db.pool.end();
    }
}

async function updateVotes(index) {
    console.log(`Updating votes: ${index}`);
    const db = makeDb();
    try {
        var rows = await db.pool.query(`UPDATE glosowanie.data SET votes = votes + 1 WHERE id = ${index + 1}`);
        
    } catch (err) {
        console.log(err);
    } finally {
        db.pool.end();
}
}

async function addVoteCodeData(code, vote){
    console.log(`Adding code: ${code} with vote: ${vote}`);
    const db = makeDb();
    try {
        var country = await db.pool.query(`SELECT * FROM glosowanie.data WHERE id = ${vote + 1}`);
        let countryName = country[0].country;
        
        var rows = await db.pool.query(`INSERT INTO glosowanie.votes (code, vote) VALUES ('${code}', '${countryName}')`);
        
    } catch (err) {
        console.log(err);
    } finally {
        db.pool.end();
    }

}
const PORT = 8000;
app.listen(PORT, ()=> console.log(`Server running on port ${PORT}`));

