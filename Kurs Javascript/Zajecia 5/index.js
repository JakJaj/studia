import express from 'express';
import si from 'systeminformation';
import cors from 'cors';

const app = express();
app.use(cors());
app.use(express.static('public'));

app.get('/api/systeminfo', async (req, res) => {
    try {
        const data = await si.get({
            cpu: 'manufacturer,brand,cores',
            mem: 'active,total',
            osInfo: 'platform',
            currentLoad: 'currentLoad',
            cpuTemperature: 'main',
            battery: 'percent'
        });
        res.json(data);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});
