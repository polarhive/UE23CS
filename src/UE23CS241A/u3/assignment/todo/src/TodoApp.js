import React, { useState } from 'react';

const styles = {
  container: {
    maxWidth: '600px',
    margin: 'auto',
    textAlign: 'center',
  },
  header: {
    fontSize: '24px',
    fontWeight: 'bold',
    margin: '20px 0',
  },
  form: {
    display: 'flex',
    flexDirection: 'column',
    marginBottom: '20px',
  },
  input: {
    padding: '10px',
    margin: '5px 0',
    fontSize: '16px',
  },
  task: {
    display: 'flex',
    justifyContent: 'space-between',
    alignItems: 'center',
    borderBottom: '1px solid #ccc',
    padding: '10px 0',
  },
  taskDescription: {
    fontSize: '18px',
    fontWeight: 'bold',
  },
  taskCompleted: {
    textDecoration: 'line-through',
    color: 'red',
  },
  editButton: {
    marginLeft: '10px',
    cursor: 'pointer',
  },
  deleteButton: {
    color: 'red',
    cursor: 'pointer',
  },
  totalCompleted: {
    marginTop: '20px',
    fontWeight: 'bold',
  },
};

const TodoApp = () => {
  const [tasks, setTasks] = useState([]);
  const [taskDesc, setTaskDesc] = useState('');
  const [taskCategory, setTaskCategory] = useState('');
  const [taskSchedule, setTaskSchedule] = useState('');
  const [isEditing, setIsEditing] = useState(false);
  const [editingTaskId, setEditingTaskId] = useState(null);

  const handleAddOrEditTask = (e) => {
    e.preventDefault();
    const newTask = {
      id: isEditing ? editingTaskId : Date.now(),
      description: taskDesc,
      category: taskCategory,
      schedule: taskSchedule,
      completed: false,
    };

    setTasks(tasks => isEditing
      ? tasks.map(task => task.id === editingTaskId ? newTask : task)
      : [...tasks, newTask]
    );

    // Reset form fields
    setIsEditing(false);
    setTaskDesc('');
    setTaskCategory('');
    setTaskSchedule('');
  };

  const handleDeleteTask = (id) => setTasks(tasks.filter(task => task.id !== id));

  const handleEditTask = (task) => {
    setIsEditing(true);
    setEditingTaskId(task.id);
    setTaskDesc(task.description);
    setTaskCategory(task.category);
    setTaskSchedule(task.schedule);
  };

  const handleToggleComplete = (id) => {
    setTasks(tasks.map(task =>
      task.id === id ? { ...task, completed: !task.completed } : task
    ));
  };

  const completedTasksCount = tasks.filter(task => task.completed).length;

  return (
    <div style={styles.container}>
      <div style={styles.header}>To Do List</div>

      <form style={styles.form} onSubmit={handleAddOrEditTask}>
        <input
          style={styles.input}
          type="text"
          placeholder="Task Description"
          value={taskDesc}
          onChange={(e) => setTaskDesc(e.target.value)}
          required
        />
        <input
          style={styles.input}
          type="text"
          placeholder="Category"
          value={taskCategory}
          onChange={(e) => setTaskCategory(e.target.value)}
          required
        />
        <input
          style={styles.input}
          type="datetime-local"
          value={taskSchedule}
          onChange={(e) => setTaskSchedule(e.target.value)}
          required
        />
        <button type="submit">{isEditing ? "Update Task" : "Add Task"}</button>
      </form>

      {tasks.map(task => (
        <div key={task.id} style={styles.task}>
          <div style={task.completed ? { ...styles.taskDescription, ...styles.taskCompleted } : styles.taskDescription}>
            <div>{task.description}</div>
            <div>Category: {task.category}</div>
            <div>Schedule: {task.schedule}</div>
            <div>Status: {task.completed ? 'Completed' : 'Scheduled'}</div>
          </div>
          <div>
            {task.completed ? (
              <button onClick={() => handleToggleComplete(task.id)}>Mark as Unchecked</button>
            ) : (
              <button onClick={() => handleToggleComplete(task.id)}>Mark as Complete</button>
            )}
            <button style={styles.editButton} onClick={() => handleEditTask(task)}>Edit</button>
            <button style={styles.deleteButton} onClick={() => handleDeleteTask(task.id)}>Delete</button>
          </div>
        </div>
      ))}

      <div style={styles.totalCompleted}>Total Completed Tasks: {completedTasksCount}</div>
    </div>
  );
};

export default TodoApp;
