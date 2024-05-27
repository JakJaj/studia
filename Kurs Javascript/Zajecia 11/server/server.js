const express = require('express');
const fs = require('fs');
const cors = require('cors');
const app = express();

app.use(cors());
app.use(express.json({ limit: '10mb' }));

app.post('/upload', (req, res) => {
    const data = req.body.image.replace(/^data:image\/\w+;base64,/, "");
    fs.writeFile('image.png', data, {encoding: 'base64'}, function(err){
        res.json({ status: 'ok' });
    });
});

app.listen(3000, () => console.log('Server started'));