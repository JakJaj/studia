let cpuData = [], memoryData = [], temperatureData = [], timeLabels = [];

function drawLineChart(canvasId, data, color) {
    const canvas = document.getElementById(canvasId);
    const ctx = canvas.getContext('2d');
    const width = canvas.width;
    const height = canvas.height;
    const minDataPoint = Math.min(...data);
    const maxDataPoint = Math.max(...data);
    const range = maxDataPoint - minDataPoint;
    const xStep = width / (data.length - 1);
    const yStep = height / range;

    //Czyszczenie canvas
    ctx.clearRect(0, 0, width, height);

    const scaleStep = range / 10;
    ctx.strokeStyle = 'gray';
    ctx.fillStyle = 'gray';
    ctx.font = '12px Arial';
    for (let i = 0; i <= 10; i++) {
        const y = height - i * yStep * scaleStep;
        ctx.beginPath();
        ctx.moveTo(0, y);
        ctx.lineTo(width, y);
        ctx.stroke();

        ctx.fillText((minDataPoint + i * scaleStep).toFixed(2), 0, y - 5);
    }

    //Rysowanie wykresu
    ctx.beginPath();
    ctx.moveTo(0, height - (data[0] - minDataPoint) * yStep);
    for (let i = 1; i < data.length; i++) {
        ctx.lineTo(i * xStep, height - (data[i] - minDataPoint) * yStep);
    }
    ctx.strokeStyle = color;
    ctx.lineWidth = 2.5;
    ctx.stroke();
}

function updateCharts() {
    drawLineChart('cpu-chart', cpuData, 'rgba(220, 60, 60, 1)');
    drawLineChart('memory-chart', memoryData, 'rgba(60, 60, 220, 1)');
    drawLineChart('temperature-chart', temperatureData, 'rgba(60, 220, 60, 1)');
}

async function fetchData() {
    const response = await fetch('http://localhost:3000/api/systeminfo');
    const data = await response.json();
    
    const currentTime = new Date().toLocaleTimeString();
    console.log(data);

    let cpuUsage = data.currentLoad && data.currentLoad.currentLoad ? data.currentLoad.currentLoad.toFixed(2) : 'N/A';
    let temperature = data.cpuTemperature && data.cpuTemperature.main ? data.cpuTemperature.main : 'N/A';
    let memoryUsage = ((data.mem.active) / (1024 * 1024 * 1024)).toFixed(2);

    cpuData.push(cpuUsage);
    memoryData.push(memoryUsage);
    temperatureData.push(temperature);
    timeLabels.push(currentTime);

    if (cpuData.length > 10) {
        cpuData.shift();
        memoryData.shift();
        temperatureData.shift();
        timeLabels.shift();
    }

    updateCharts();
    console.log("Data updated");
    document.getElementById('cpu-usage').innerText = "Current: " + cpuUsage + "%";
    document.getElementById('memory-usage').innerText = "Current: " + memoryUsage + " GB";
    document.getElementById('temperature').innerText = "Current: " + temperature + "°C";
    document.getElementById('cpu-model').innerText = "CPU Model: " + data.cpu.manufacturer + " " + data.cpu.brand;
    document.getElementById('cpu-cores').innerText = "CPU Cores: " + data.cpu.cores;
    document.getElementById('total-memory').innerText = "Total Memory: " + (data.mem.total / (1024 * 1024 * 1024)).toFixed(2) + " GB";
    document.getElementById('os-name').innerText = "OS: " + data.osInfo.platform.charAt(0).toUpperCase() + data.osInfo.platform.slice(1);
    document.getElementById('battery-charge').innerText = "Battery: " + (data.battery.percent || 'N/A') + "%";
}

fetchData();
setInterval(fetchData, 2000);