import express from "express";
import { dirname } from "path";
import { fileURLToPath } from "url";
import qr from "qr-image";
import fs from "fs";
import bodyParser from "body-parser";

const port = 3000;
const app = express();
const __dirname = dirname(fileURLToPath(import.meta.url));

app.use(bodyParser.urlencoded({extended: true}));


app.get('/', (req, res) => {
    res.sendFile(__dirname + '/public/index.html');
});

app.post('/submit', (req, res) => {
    const data = req.body.url;
    let path = __dirname + "/public/temp.png";

    let qr_png = qr.image(data);
    
    qr_png.pipe(fs.createWriteStream(path));

    res.sendFile(path, (err) => {
        if(err) {
            console.log(err);
        }
    });
});

app.listen(port, () => {
    console.log(`Server is running at http://localhost:${port}`)
})