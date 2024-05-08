const buttons = document.querySelectorAll('[data-index]');
const connected = document.querySelector('.connected');
let selected = -1;
let keys = [];
const submit = document.querySelector('#submit');
const passcode = document.querySelector('#passcode');

const ctx = document.querySelector('#myChart').getContext('2d');

let chartData = {
    labels : ['Italian', 'Indian', 'Spanish', 'Chinese', 'Japanese', 'Mexican'],
    datasets: [{
        label:'Votes',
        data:[0,0,0,0,0,0],
        backgroundColor:[
            'rgba(1,180,32,0.2)',
            'rgba(1,180,32,0.2)',
            'rgba(1,180,32,0.2)',
            'rgba(1,180,32,0.2)',
            'rgba(1,180,32,0.2)',
            'rgba(1,180,32,0.2)'
        ],
        borderColor:[
            'rgba(1,150,32,1)',
        ],
        borderWidth:2
    }]
};
const myChart = new Chart(ctx, {
    type:'bar',
    data: chartData
});

buttons.forEach(b=>{
    b.onclick = ()=>{
        buttons.forEach(b=> b.classList.remove('picked'));
        b.classList.add('picked');
        selected = b.dataset.index;
    };
});

submit.onclick = ()=>{

    console.log(keys);
    console.log(passcode.value);

    if(selected === -1){
        alert('Please pick your vote before submitting');
        return;
    }
    if(passcode.value === ""){
        alert('Please enter the passcode');
        return;
    }
    if(keys.indexOf(passcode.value) === -1){
        alert('Incorrect or inactive passcode');
        return;
    }
    
    let index = keys.indexOf(passcode.value);
    
    console.log(index)
    console.log(keys)
    keys.splice(index, 1);
    console.log(keys);

    chartData.datasets[0].data[selected] += 1;
    buttons.forEach(b=> b.disabled = true);
    ws.send(JSON.stringify({data:chartData.datasets[0].data, keys:keys}));
    
    selected = -1;
};

const ws = new WebSocket('ws://localhost:8080');
ws.addEventListener('open', ()=>{
    console.log('Connection opened.');
    connected.textContent = 'You can now vote!';
    connected.classList.add('active');
});
ws.addEventListener('close',()=>{
    console.log('Disconnected.');
    connected.textContent = 'Refresh a page to vote!';
    connected.classList.remove('active');
});
ws.addEventListener('message', e =>{
    let {data} = e;
    let newData = JSON.parse(data);
    newData.data.forEach((d, index)=>{
        chartData.datasets[0].data[index] = +d;
    });
    myChart.update();
    keys = newData.keys;
});