document.addEventListener('DOMContentLoaded', () => {
    const todoForm = document.getElementById('todo-form');
    const todoList = document.getElementById('todo-list');
    const newTaskInput = document.getElementById('new-task');

    // List of initial tasks
    const tasks = [
        'Implement a class BinaryTree',
        'Create the class CRRPricer',
        'Create the class EuropeanDigitalOption',
        'Create the derived class EuropeanDigitalCallOption from EuropeanDigitalOption',
        'Create the derived class EuropeanDigitalPutOption from EuropeanDigitalOption',
        'Augment the Option class with payoffPath method',
        'Create the derived class AsianOption from Option',
        'Create the derived class AsianCallOption from AsianOption',
        'Create the derived class AsianPutOption from AsianOption',
        'Augment the Option class with bool isAsianOption()',
        'Modify the CRRPricer constructor to throw an error if the option is an Asian option',
        'Design a singleton class MT',
        'Write the BlackScholesMCPricer class',
        'Augment the Option class with bool isAmericanOption()',
        'Create the derived class AmericanOption from Option',
        'Create the derived class AmericanCallOption from AmericanOption',
        'Create the derived class AmericanPutOption from AmericanOption',
        'Modify CRRPricer in order for it to price properly American options',
        'Overload the CRRPricer constructor',
        'Test with the test file'
    ];

    // Function to add a task to the list
    const addTask = (task) => {
        const li = document.createElement('li');
        li.textContent = task;
        li.addEventListener('click', () => {
            li.classList.toggle('done');
        });
        todoList.appendChild(li);
    };

    // Initialize with the predefined tasks
    tasks.forEach(task => addTask(task));

    // Handle form submission
    todoForm.addEventListener('submit', (e) => {
        e.preventDefault();
        const task = newTaskInput.value.trim();
        if (task) {
            addTask(task);
            newTaskInput.value = '';
        }
    });
});