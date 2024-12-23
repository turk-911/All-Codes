from flask import Flask, render_template, redirect, url_for, flash
from flask_pymongo import PyMongo
from forms import PostForm
app = Flask(__name__)
app.config['MONGO_URI'] = ''
app.config['SECRET_KEY'] = '121212'
mongo = PyMongo(app)
@app.route('/', methods=['GET', 'POST'])
def index():
    form = PostForm()
    if form.validate_on_submit():
        mongo.db.posts.insert_one({
            'title': form.title.data,
            'content': form.content.data
        })
        flash('Your post has been created   ')