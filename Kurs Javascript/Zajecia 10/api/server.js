import express from "express";
import makeDb from "./database.js";
import cors from "cors";
import crypto from "crypto";
import dotenv from 'dotenv';
dotenv.config();
const encryptionKey = Buffer.from(process.env.ENCRYPTION_KEY, 'base64');

const app = express();
app.use(cors());
app.use(express.json());

let tasks = await getTasks();

app.get('/api/gettasks', (req, res) => {
    
    console.log("POBRANIE ZADAN")
    res.json(tasks);
});

app.post('/api/addtasks', (req, res) => {
    console.log("DODANIE ZADANIA")
    addTasks(req.body);
    tasks = req.body;
    res.json({ code: "200" });
});

async function getTasks(){
    const db = makeDb();
    const tasks = [];
    try{
        var rows = await db.pool.query("SELECT * FROM todo.tasks");

        for (let i = 0; i < rows.length; i++) {
            tasks.push({
                id: rows[i].id,
                name: decryptData(rows[i].name,encryptionKey, encryptionKey),
                description: decryptData(rows[i].description,encryptionKey, encryptionKey),
                done: rows[i].done
            });
        }
    } catch (e) {
        console.error(e);
    } finally { 
        db.pool.end();
    }
    
    return { tasks: tasks };
}

async function addTasks(data){
    const db = makeDb();
    try{
        await db.pool.query("DELETE FROM todo.tasks WHERE 1=1;")
        for (let i = 0; i < data.tasks.length; i++) {
            await db.pool.query("INSERT INTO todo.tasks (name, description, done) VALUES (?, ?, ?)", [encryptData(data.tasks[i].name,encryptionKey), encryptData(data.tasks[i].description,encryptionKey), data.tasks[i].done]);
        }
    } catch (e) {
        console.error(e);
    } finally { 
        db.pool.end();
    }   
}

app.get('/api/cipher', (req, res) => {

    let text = "Hello beautifull world!";
    let encrypted = encryptData(text, encryptionKey);
    let decrypted = decryptData(encrypted, encryptionKey);

    res.json({ test: [text, encrypted, decrypted] });
});


function encryptData(plainText, key) {
    if (key.length !== 32) {
        throw new Error('Invalid key length');
    }
    const iv = crypto.randomBytes(16);
    const cipher = crypto.createCipheriv('aes-256-cbc', key, iv);
    let cipherText = cipher.update(plainText, 'utf8', 'hex');
    cipherText += cipher.final('hex');
    return iv.toString('hex') + ':' + cipherText;
}

function decryptData(cipherText, key) {
    if (key.length !== 32) {
        throw new Error('Invalid key length');
    }
    const textParts = cipherText.split(':');
    const iv = Buffer.from(textParts.shift(), 'hex');
    if (iv.length !== 16) {
        throw new Error('Invalid IV length');
    }
    const encryptedText = Buffer.from(textParts.join(':'), 'hex');
    const decipher = crypto.createDecipheriv('aes-256-cbc', key, iv);
    let decrypted = decipher.update(encryptedText, 'utf8');
    decrypted += decipher.final('utf8');
    return decrypted;
}

const port = 3000;
app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});