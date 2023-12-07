# Documentation

## Process
Since my final website is a completely different idea than my midterm website, I started by coding the general structure and format of the website. To do this, I used the help of Bootstrap for the navigation bar and its grid system -- while modifying the style a bit using CSS.

```html
<!-- Personality Traits dropdown menu -->
<li class="nav-item dropdown">
    <a
    href="#"
    role="button"
    data-bs-toggle="dropdown"
    aria-expanded="false"
    class="nav-link dropdown-toggle"
    >
    Personality Traits
    </a>
    <ul class="dropdown-menu dropdown-menu-end">
    <li><a class="dropdown-item" href="o.html">O</a></li>
    <li><a class="dropdown-item" href="c.html">C</a></li>
    <li><a class="dropdown-item" href="e.html">E</a></li>
    <li><a class="dropdown-item" href="a.html">A</a></li>
    <li><a class="dropdown-item" href="n.html">N</a></li>
    </ul>
</li>
```
<sub>**Code Block 1**: Snippet of code from the navigation bar.</sub>

This took care of all my pages except for the Personality Test page, which required some Javascript. The Javascript for this page calculated the user's score result after they had completed the test and clicked on the <em>Submit</em> button. This score was calculated using the values initially set in the radio button.

```javascript
function calc_score() {
    const q1 = parseInt(
        document.querySelector("input[name=q1]:checked").value
    );
    const q2 = parseInt(
        document.querySelector("input[name=q2]:checked").value
    );
    // ... (q3 - q58)
    const q59 = parseInt(
          document.querySelector("input[name=q59]:checked").value
        );
        const q60 = parseInt(
          document.querySelector("input[name=q60]:checked").value
        );

    n_score = q1 + q6 + q11 + q16 + q21 + q26 + q31 + q36 + q41 + q46 + q51 + q56;
    e_score = q2 + q7 + q12 + q17 + q22 + q27 + q32 + q37 + q42 + q47 + q52 + q57;
    o_score = q3 + q8 + q13 + q18 + q23 + q28 + q33 + q38 + q43 + q48 + q53 + q58;
    a_score = q4 + q9 + q14 + q19 + q24 + q29 + q34 + q39 + q44 + q49 + q54 + q59;
    c_score = q5 + q10 + q15 + q20 + q25 + q30 + q35 + q40 + q45 + q50 + q55 + q60;
      }
```
<sub>**Code Block 2**: Getting the user's answer choice for each question and adding the points to the respective personality trait score.</sub>


Along with displaying the user's personality trait scores for the result, I had implemented a graph that showcased the weights of each of the personality traits -- giving a visual of what the user's personality looks like. For the implementation of this graph, I used the Chart.js library.

```html
<script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
```
<sub>**Code Block 3**: First, include Chart.js in your HTML by adding the following line in the head tag of the HTML file.</sub>

```html
<canvas id="scoreChart" width="400" height="200"></canvas>
```
<sub>**Code Block 4**: Add a canvas element where the chart will be displayed.

```javascript
const ctx = document.getElementById("scoreChart").getContext("2d");
const scoreChart = new Chart(ctx, {
    type: "line",
    data: {
    labels: ["N", "E", "O", "A", "C"],
    datasets: [{
        label: "Scores",
        data: [n_score, e_score, o_score, a_score, c_score],
        backgroundColor: "rgba(54, 162, 235, 0.2)",
        borderColor: "rgba(54, 162, 235, 1)",
        borderWidth: 1.5
    }]
    },
    options: {
    scales: {
        y: {
        beginAtZero: true,
        max: 50
        }
    }
    }
});
```
<sub>**Code Block 5**: Adapt the existing JavaScript code to create a line chart using Chart.js with the scores.

So once the user clicks the <em>Submit</em> button, the result will display both the individual personality traits score and the graph.

Overall, there weren't really any issues I encountered when creating this website. The only time-consuming part was manually typing out all 60 questions/statements for the test. There was also a point where I realized each radio button needed its own ID for the input and label. So, I basically had to do a lot of renaming.

## What I learned in order to accomplish the project
- Bootstrap's Grid System
    - Understanding rows and cols
- Chart.js
    - Reading the documentation and watching Youtube tutorials

## Next Steps
Because I focused and spent most of my time working on the Javascript and the whole Personality Test page, I would say the visual design and looks of the website lack a bit -- personally, I think it looks very plain and could be better. So, if I had more time, I would spend it by working on the visual side of the website like maybe adding a bit of color or images.