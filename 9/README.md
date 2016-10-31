# Section 9

## Python Decorators

Python decorators allow you to modify a function.

Consider the following example:

```
def override(func):
    def incr():
        return func() + 1
    return incr

@override
def one():
    return 1

print(one()) # prints 2
```

In the above example we first define a function `override`, which takes in a **function** as an argument and then returns a **function** that returns the return value of the original arugment plus 1. We then use this function as a **decorator** on the function `one`. Originally one would have returned `1`, but now it has been overridden and hence will return `2` instead.

## Flask

Flask is a Python-based web microframework that automates the process of building simple web apps.
Typical Flask applications are written in a file called `application.py`. You can think of Flask like a traffic cop - It listens to incoming requests from clients and then acts appropriately.

A simple Flask app might look like this:
```
from flask import Flask

app = Flask(__name__)

@app.route("/")
def index():
    return "You are at the index!"

@app.route("/sample")
def sample():
    return "You have reached the sample page!"
``` 

In this example we first import flask, then make a new app and finally define two routes. To define the route we use the `@app.route()` decorator. A route specifies what should be done when the user visits the app at a certain index. In the above example we defined two routes: `/` and `/sample`. If this app was running on the domain `http://www.myapp.com` then now when the user would go to `http://www.myapp.com/` then the user would see "You are at the index!". If the user would visit `http://www.myapp.com/sample`, then the user would see "You have reached the sample page!"

For this pset, the distribution code will come with the decorator `@login-required`, which you can use to restrict functions to users who have logged in.

## Jinja

Jinja is a python inspired templating language. It allows you to make `.html` files dynamic, by allowing jinja to dynamically add parts to the page. With Jinja you would usually have a file called `layout.html`, which then gets extended with different blocks depending on which page the user is on.

## SQL

SQL is programming language which is used for managing and manipulating data in relation databases.
In this pset you will use a SQLite database. SQLlite databases are stored in a `.db` file. In order to insert, delete or modify the data in the database you will use SQL queries.

These are the 4 basic queries you should be comfortable with:

### Update

Update is used for changing already existing data in the database.

Example:

```
UPDATE table SET col1 = val1, col2 = val2, ... # update table, changing values in particular columns

UPDATE table SET col1 = val1 WHERE identifier = "name" # update table, changing col1 to val1 where "name" equals "identifier"
```

### Insert Into
Insert into is used to insert certain values into a table.

Example:

```
INSERT INTO table VALUES values # insert into table the row of values

INSERT INTO table (col1, col2) VALUES (val1, val2) # insert into table under columns col1 & col2, val1 & val2
```

### Select
Select is used for retrieving data from the database.

Example:

```
SELECT col FROM table WHERE col = "identifier" # select a column from table to compare/ view

SELECT * FROM table # select all columns from a table
```

### Delete
Delete is used to delete exising data from the database

Example:

```
DELETE FROM table WHERE col = "identifier" # delete a row from table
```

To execute a SQL query in Flask you can used the provided `db.execute()` function.

To manipulate a database directly (this will come in handy when setting your database up) you will use **phpliteadmin**. To run phpliteadmin run the following command in the IDE, substituting `mydatabase.db` for the name of your database file:
```
$ phpliteadmin mydatabase.db
```
