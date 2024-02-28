document.getElementById('dynamicForm').addEventListener('submit', function(event) {
    event.preventDefault();
    var inputCount = parseInt(document.getElementById('inputCount').value);
    benchmark(inputCount);
});

function benchmark(inputCount) {
    var startTime, endTime;

    // Creation
    startTime = performance.now();
    createInputFields(inputCount);
    endTime = performance.now();
    document.getElementById('creationTime').textContent = (endTime - startTime).toFixed(2);

    // Writing
    startTime = performance.now();
    writeInputValues();
    endTime = performance.now();
    document.getElementById('writingTime').textContent = (endTime - startTime).toFixed(2);

    // Reading
    startTime = performance.now();
    readInputValues();
    endTime = performance.now();
    document.getElementById('readingTime').textContent = (endTime - startTime).toFixed(2);

    // Deletion
    startTime = performance.now();
    deleteInputFields();
    endTime = performance.now();
    document.getElementById('deletionTime').textContent = (endTime - startTime).toFixed(2);
}

function createInputFields(count) {
    var form = document.getElementById('dynamicForm');
    for (var i = 0; i < count; i++) {
        var input = document.createElement('input');
        input.type = 'text';
        input.name = 'inputField';
        form.appendChild(input);
    }
}

function writeInputValues() {
    var inputs = document.getElementsByName('inputField');
    for (var i = 0; i < inputs.length; i++) {
        inputs[i].value = 'Value ' + (i + 1);
    }
}

function readInputValues() {
    var inputs = document.getElementsByName('inputField');
    for (var i = 0; i < inputs.length; i++) {
        var value = inputs[i].value;
        console.log('Input ' + (i + 1) + ': ' + value);
    }
}

function deleteInputFields() {
    var form = document.getElementById('dynamicForm');
    while (form.firstChild) {
        form.removeChild(form.firstChild);
    }
}