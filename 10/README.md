# Section 10

## Javascript

Javascript is a dynamic programming language used by web browsers on the **Client side** that allows users to communicate **asynchronously** with the browser.

**Client side** means that the code is executed on the users computer as opposed to on the server. This is much faster since you don't have to communicate with another device.

**Asynchronously** means that one piece of code doesn't necessarily need to wait until another finishes.

Javascript has characteristics from multiple programming paradigms such as functional programming, object-oriented programming, imperative programming and so on. A few characteristic features of Javascript are:

* Just like with Python, you don't need to compile Javascript.
* It's dynamically typed. In order to declare a variable of any type you can just use the `var` keyword.
* Its ability to use the `DOM` (document object model) to dynamically change `HTML` is one reason why it is so widely used throughout the world wide web.

### Basic syntax

Data structures:
```
// a simple variable
var age = 20;

// an array
var array = [1, 2, 3, 4, 5];

// string
var str = "This is CS50!";

// an object
var teacher = {name: "David", course: 50};
```

Note the new `object` datatype. Javascript objects are very similar to Python dictionaries.

Conditions and loops:
```
// while loop
while (true)
{
    // do something
}

// for loop
for (int i = 0; i < 50; i++)
{
    // do something
}

// if condition
if (true)
{
    // do something
}
```

For each loops:
Similarly to Python Javascript also has for each loops. The syntax is as follows:
```
// for arrays
var my_arr = [1,2,3];

for (var x of my_arr) {
    console.log(x);     // 1
                        // 2
                        // 3
}

// for objects
for my_obj = {a: 10, b: 20};

for (var x in my_obj) {
    console.log(x);     // 10
                        // 20
}

```

Notice the difference between `in` and `of`.

For printing we use `console.log()`.


## The DOM

The **DOM** or Document Object Model is a hierarchical way of laying out information.

Let's look at an example of what a DOM tree might look like.
Let's say we have this HTML file:

```
<!DOCTYPE html>
    <head>
        <title id="title">Hey Rob!</title>
    </head>
    <body>
        <div>
            <img id="pic" src="rob.jpg" alt="rob">
        </div>
        <div>
            <p id="quote">There is no happiness in the world, only rice...</p>
        </div>
    </body>
</html>
```

The corresponding DOM tree would be:
```
             [HTML]
              /   \
             /     \
         [head]    [body]
           /        /  \
          /        /    \
         /        /      \
     [title]    [div]   [div]
        |        |        |
  ("Hey, Rob!") [p]     [img]
                 |
         ("There is no ...")

```


With Javascript we can dynamically change the DOM without having to reload the page. For example, take a look at the following code:

```
    var title = document.getElementById("title");
    title.innerHTML = "David";

    var pic = document.getElementById("pic");
    pic.src = "david.jpg";

    var alt = document.getElementById("pic");
    alt.alt = "david";

    document.getElementById("quote").innerHTML = "alllllright";
```

Here `document.getElementById()` searches the DOM for an element with the specified id and returns it. You can then change attributes of that element by using the `.` operator.


This power coudl for example be leveraged to validate forms client side, so the user would get instant feedback. For an example of this see the following:

```
 var form = document.getElementById('registration'); 

    // onsubmit
    form.onsubmit = function() { 

        // validate email
        if (form.email.value == '') 
        {
            alert('You must provide your email address!');
            return false;
        }

        // validate password
        else if (form.password.value == '')
        {
            alert('You must provide a password!');
            return false;
        }

        // validate confirmation
        else if (form.password.value != form.confirmation.value) 
        {
            alert('Passwords do not match!');
            return false;
        }

        // validate agreement
        else if (!form.agreement.checked) 
        {
            alert('You must agree to the terms and conditions!');
            return false;
        }

        // valid!
        return true; 

    };

```
