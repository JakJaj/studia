document.getElementById('dynamicForm').addEventListener('submit', function(event) {
    event.preventDefault();
    let numberPassed = parseInt(document.getElementById('numberPassed').value);
    benchmark(numberPassed);

});

function benchmark(numberPassed) {
    let start, end;

    // Tworzenie
    start = performance.now();
    createInputFields(numberPassed);
    end = performance.now();
    document.getElementById('creationTime').textContent = (end - start).toFixed(2);

    // Pisanie
    start = performance.now();
    writeInputValues();
    end = performance.now();
    document.getElementById('writingTime').textContent = (end - start).toFixed(2);

    // Czytanie
    start = performance.now();
    readInputValues();
    end = performance.now();
    document.getElementById('readingTime').textContent = (end - start).toFixed(2);

    // Usuwanie
    start = performance.now();
    deleteInputFields();
    end = performance.now();
    document.getElementById('deletionTime').textContent = (end - start).toFixed(2);
}

function createInputFields(count) {
    let form = document.getElementById('tempForm');
    for (let i = 0; i < count; i++) {
        let input = document.createElement('input');
        input.type = 'text';
        input.name = 'inputField';
        form.appendChild(input);
    }
}

function writeInputValues() {
    let inputs = document.getElementsByName('inputField');
    for (let i = 0; i < inputs.length; i++) {
        inputs[i].value = 'Value ' + (i + 1);
    }
}

function readInputValues() {
    let inputs = document.getElementsByName('inputField');
    for (let i = 0; i < inputs.length; i++) {
        let value = inputs[i].value;
        console.log('Input ' + (i + 1) + ': ' + value);
    }
}

function deleteInputFields() {
    let form = document.getElementById('tempForm');
    while (form.firstChild) {
        form.removeChild(form.firstChild);
    }
}