import React, { useState } from 'react';

const styles = {
  container: {
    maxWidth: '600px',
    margin: 'auto',
    padding: '20px',
    borderRadius: '8px',
    textAlign: 'center',
    boxShadow: '0 4px 6px rgba(0, 0, 0, 0.1)',
  },
  header: {
    fontSize: '24px',
    fontWeight: 'bold',
    margin: '20px 0',
  },
  form: {
    display: 'flex',
    flexDirection: 'column',
    gap: '10px',
    marginBottom: '20px',
  },
  input: {
    padding: '12px',
    borderRadius: '6px',
    fontSize: '16px',
    boxShadow: 'inset 0 1px 2px rgba(0, 0, 0, 0.1)',
  },
  button: {
    padding: '12px',
    borderRadius: '6px',
    fontSize: '16px',
    fontWeight: 'bold',
    cursor: 'pointer',
    border: 'none',
    boxShadow: '0 2px 4px rgba(0, 0, 0, 0.2)',
    transition: 'background-color 0.2s ease',
  },
  task: {
    display: 'flex',
    justifyContent: 'space-between',
    alignItems: 'center',
    padding: '12px',
    borderRadius: '6px',
    marginBottom: '10px',
    boxShadow: '0 2px 4px rgba(0, 0, 0, 0.1)',
  },
  taskDescription: {
    fontSize: '18px',
    fontWeight: 'bold',
  },
  taskCompleted: {
    textDecoration: 'line-through',
  },
  editButton: {
    cursor: 'pointer',
    marginLeft: '10px',
  },
  deleteButton: {
    cursor: 'pointer',
    marginLeft: '10px',
  },
  totalCompleted: {
    marginTop: '20px',
    fontSize: '16px',
    fontWeight: 'bold',
  },
};

const lightTheme = {
  container: {
    backgroundColor: '#f9fafb',
    color: '#1f2937',
  },
  header: {
    color: '#1f2937',
  },
  input: {
    backgroundColor: '#fff',
    color: '#374151',
    border: '1px solid #d1d5db',
  },
  task: {
    backgroundColor: '#fff',
    color: '#374151',
    border: '1px solid #e5e7eb',
  },
  button: {
    backgroundColor: '#3b82f6',
    color: '#fff',
  },
  editButton: {
    color: '#3b82f6',
  },
  deleteButton: {
    color: '#ef4444',
  },
  totalCompleted: {
    color: '#1f2937',
  },
};

const darkTheme = {
  container: {
    backgroundColor: '#1f2937',
    color: '#f3f4f6',
  },
  header: {
    color: '#f3f4f6',
  },
  input: {
    backgroundColor: '#374151',
    color: '#f3f4f6',
    border: '1px solid #4b5563',
  },
  task: {
    backgroundColor: '#374151',
    color: '#f3f4f6',
    border: '1px solid #4b5563',
  },
  button: {
    backgroundColor: '#2563eb',
    color: '#f3f4f6',
  },
  editButton: {
    color: '#93c5fd',
  },
  deleteButton: {
    color: '#f87171',
  },
  totalCompleted: {
    color: '#f3f4f6',
  },
};

const TodoApp = () => {
  const [tasks, setTasks] = useState([]);
  const [taskDesc, setTaskDesc] = useState('');
  const [taskCategory, setTaskCategory] = useState('');
  const [taskSchedule, setTaskSchedule] = useState('');
  const [isEditing, setIsEditing] = useState(false);
  const [editingTaskId, setEditingTaskId] = useState(null);
  const [isDarkMode, setIsDarkMode] = useState(false);

  const theme = isDarkMode ? darkTheme : lightTheme;

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
    <div style={{ ...styles.container, ...theme.container }}>
      <div style={{ ...styles.header, ...theme.header }}>To Do List</div>

      <button
        onClick={() => setIsDarkMode(!isDarkMode)}
        style={{
          ...styles.button,
          ...theme.button,
          marginBottom: '20px',
        }}
      >
        {isDarkMode ? 'Switch to Light Mode' : 'Switch to Dark Mode'}
      </button>

      <form style={{ ...styles.form, gap: '10px', marginBottom: '20px' }} onSubmit={handleAddOrEditTask}>
        <input
          style={{ ...styles.input, ...theme.input }}
          type="text"
          placeholder="Task Description"
          value={taskDesc}
          onChange={(e) => setTaskDesc(e.target.value)}
          required
        />
        <input
          style={{ ...styles.input, ...theme.input }}
          type="text"
          placeholder="Category"
          value={taskCategory}
          onChange={(e) => setTaskCategory(e.target.value)}
          required
        />
        <input
          style={{ ...styles.input, ...theme.input }}
          type="datetime-local"
          value={taskSchedule}
          onChange={(e) => setTaskSchedule(e.target.value)}
          required
        />
        <button
          type="submit"
          style={{ ...styles.button, ...theme.button }}
        >
          {isEditing ? "Update Task" : "Add Task"}
        </button>
      </form>

      {tasks.map(task => (
        <div key={task.id} style={{ ...styles.task, ...theme.task }}>
          <div style={task.completed ? { ...styles.taskDescription, ...styles.taskCompleted } : theme.taskDescription}>
            <div>{task.description}</div>
            <div>Category: {task.category}</div>
            <div>Schedule: {task.schedule}</div>
            <div>Status: {task.completed ? 'Completed' : 'Scheduled'}</div>
          </div>
          <div>
            <button onClick={() => handleToggleComplete(task.id)}>
              {task.completed ? 'Mark as Unchecked' : 'Mark as Complete'}
            </button>
            <button style={{ ...styles.editButton, color: theme.editButton.color }} onClick={() => handleEditTask(task)}>Edit</button>
            <button style={{ ...styles.deleteButton, color: theme.deleteButton.color }} onClick={() => handleDeleteTask(task.id)}>Delete</button>
          </div>
        </div>
      ))}

      <div style={{ ...styles.totalCompleted, color: theme.totalCompleted.color }}>
        Total Completed Tasks: {completedTasksCount}
      </div>
    </div>
  );
};

export default TodoApp;
