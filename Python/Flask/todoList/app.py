from flask import Flask, jsonify, request
from flask_cors import CORS  # Import CORS

app = Flask(__name__)
CORS(app)  

tasks = []

# Route to get all tasks
@app.route('/tasks', methods=['GET'])
def get_tasks():
    return jsonify(tasks)

# Route to add a new task
@app.route('/tasks', methods=['POST'])
def add_task():
    task_data = request.get_json()
    task = {
        'id': len(tasks) + 1,
        'title': task_data['title'],
        'completed': False
    }
    tasks.append(task)
    return jsonify(task), 201

# Route to delete a task by ID
@app.route('/tasks/<int:task_id>', methods=['DELETE'])
def delete_task(task_id):
    global tasks
    tasks = [task for task in tasks if task['id'] != task_id]
    return jsonify({'message': 'Task deleted'}), 200

# Route to update a task's completion status
@app.route('/tasks/<int:task_id>', methods=['PUT'])
def update_task(task_id):
    task_data = request.get_json()
    for task in tasks:
        if task['id'] == task_id:
            task['completed'] = task_data['completed']
            return jsonify(task)
    return jsonify({'message': 'Task not found'}), 404

if __name__ == '__main__':
    app.run(debug=True)