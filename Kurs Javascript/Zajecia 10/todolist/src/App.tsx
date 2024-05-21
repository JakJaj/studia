import './App.css'
import trashCan from '/trash.svg'
import check from '/check.svg'
import { useState, useEffect } from 'react'
interface Task {
  name: string;
  description: string;
  done: boolean;
  id: number;
}

function App() {
  //TODO: szyfrowanie zadań
  

  const [tasks, setTasks] = useState<Task[]>([]);
  useEffect(() => {
    fetch('http://localhost:3000/api/gettasks')
      .then(response => response.json())
      .then(data => {
      //console.log(data)
      setTasks(data.tasks)
    });
  }, []);

  const taskList = tasks.map(task => 
    <Task taskName={task.name} taskDescription={task.description} taskDone={task.done} id={task.id} key={task.id} />
  )
    
  return (
    <>

      <ActionPanel />
      <div className='taskPanelPlacement'>
      <div className='taskPanel'>
        <div className='taskList'>
        {taskList.length > 0 ? taskList : <h1>Brak zadań</h1>}
        </div>
      </div>
      </div>
    </>
  )

  function ActionPanel(){
    const [isOpen, setIsOpen] = useState(false);
    const [taskName, setTaskName] = useState('');
    const [taskDescription, setTaskDescription] = useState('');

    const closeOnOverlayClick = (e: React.MouseEvent) => {
      if (e.target === e.currentTarget) {
        setIsOpen(false);
      }
    }

    const handleNameChange = (e: React.ChangeEvent<HTMLInputElement>) => {
      setTaskName(e.target.value);
    }
    const handleDescriptionChange = (e: React.ChangeEvent<HTMLInputElement>) => {
      setTaskDescription(e.target.value);
    }

    function addTask() {

      if (taskName === '') {
        return;
      }

      const newTask = {
        id: tasks.length + 1,
        name: taskName,
        description: taskDescription,
        done: false
      }
      const updatedTasks = [...tasks, newTask];
      
      setTasks(updatedTasks);
      saveData(updatedTasks);
      console.log(updatedTasks);
      
      setTaskName('');
      setTaskDescription('');
      setIsOpen(false);
      
    }

    return(
      <div className='actionPanel'>
        <h1>Moje zadania</h1>
        <button className='addButton' onClick={() => setIsOpen(true)}>Dodaj zadanie</button>
        {isOpen && (
          <div className='popup' onClick={closeOnOverlayClick}>
            <div className='popupBox'>
                <h1>Dodaj nowe zadanie</h1>

                <input 
                  type='text'
                  className='popupInput' 
                  placeholder='Nazwa zadania (wymagana)'
                  value={taskName}
                  onChange={handleNameChange}>
                </input>

                <input 
                  className='popupInput' 
                  placeholder='Opis zadania'
                  value={taskDescription}
                  onChange={handleDescriptionChange}>
                  </input>

                <button onClick={addTask}
                    className='popupButton'>
                      Dodaj zadanie
                </button>
            </div>
          </div>
        )}
      </div>
    )
  }

  type TaskProps = {
    taskName: string;
    taskDescription: string;
    taskDone: boolean;
    id: number;
  };


  function Task({taskName, taskDescription, taskDone, id}: TaskProps) {

    function toggleTask() {
      
      const newTasks = [...tasks];
    
      const task = newTasks.find(task => task.id === id);
      if (task) {
        task.done = !task.done;
      }
      saveData(tasks);
      setTasks(newTasks);
      console.log(tasks);
      
    }

    function deleteTask() {
      const newTasks = tasks.filter(task => task.id !== id);
      saveData(newTasks);
      setTasks(newTasks); 
    }

      return(
        <div className={`task ${taskDone ? 'done' : ''}`}>
          <div className='taskText'>
          <h1>{taskName}</h1>
          <p>{taskDescription}</p>
          </div>
          
          <div className={` taskButton ${taskDone ? 'buttonDone' : ''}`}>
            <button onClick={toggleTask}><img src={check}></img></button>
            
            <button onClick={deleteTask} className='deleteButton'><img src={trashCan}></img></button>
          </div>
        </div>
      );
    }
}

function saveData(data: Task[]) {
  fetch('http://localhost:3000/api/addtasks', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json'
    },
    body: JSON.stringify({ tasks: data })
  });
}

export default App
