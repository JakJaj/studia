import express from "express";
import WebSocket, { WebSocketServer } from "ws";
const app = express();
import fs from "fs";

app.use(express.static("public"));

let jsonData = JSON.parse(fs.readFileSync("data.json"));
let jsonKeys = JSON.parse(fs.readFileSync("keys.json"));

const wss = new WebSocketServer({ port: 8080 });
wss.on("connection", (ws, res) => {
  ws.on("message", (data) => {
    let newData = JSON.parse(data.toString());

    newData.data.forEach((d, index) => {
      jsonData.data[index] = +d;
    });

    console.log(newData);

    jsonKeys.keys = newData.keys;

    let updatedData = JSON.stringify(jsonData, null, 2);
    let updatedKeys = JSON.stringify(jsonKeys, null, 2);
    console.log(updatedKeys);

    fs.writeFileSync("data.json", updatedData);
    fs.writeFileSync("keys.json", updatedKeys);
    let date = new Date().toLocaleDateString();
    let time = new Date().toLocaleTimeString();
    let datetime = (date + " " + time).toString();

    wss.clients.forEach((c) => {
      if (c.readyState === WebSocket.OPEN) {
        c.send(
          JSON.stringify({
            time: datetime,
            message: `Updated data`,
            data: jsonData.data,
            keys: jsonKeys.keys,
          }),
        );
      }
    });
  });

  let date = new Date().toLocaleDateString();
  let time = new Date().toLocaleTimeString();
  let datetime = (date + " " + time).toString();
  ws.send(
    JSON.stringify({
      time: datetime,
      message: `Welcome from the Server`,
      data: jsonData.data,
      keys: jsonKeys.keys,
    }),
  );
});

const PORT = 8000;
app.listen(PORT, () => console.log(`Server listening on port ${PORT}`));
