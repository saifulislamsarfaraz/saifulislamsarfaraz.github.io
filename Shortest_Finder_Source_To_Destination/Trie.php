<!DOCTYPE html>
<html>

<head>

    <title>CSE PROJECT</title>
    <link rel="icon" href="https://assets.stickpng.com/images/58afdad6829958a978a4a693.png">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css"
        integrity="sha384-9aIt2nRpC12Uk9gS9baDl411NQApFmC26EwAOH8WgZl5MYYxFfc+NcPb1dKGj7Sk" crossorigin="anonymous">
    <link rel="stylesheet" href="style.css">
</head>
<?php include("watertext.php")?> 
<body>
    <header>
        <div class="container">
       
        <h1 class="top">CSE 246 - Project</h1>
            <h2>Find shortest path your destination</h2>
        </div>
    </header>
    <main>
        <div class="top">
            <div class="input-group mb-3">
                <input type="text" class="form-control" placeholder="Type Where you want to go!!!" id="text-field">
            </div>
            <ul id="list" class="list-group">
            </ul>
        <div class="grd">
            <?php include("index.php")?>    
            </div>
        </div>
    </main>

    
    <script src="TrieScript.js"></script>
    <script src="triedataRead.js"></script>
    <script src="mapScript.js"></script>
    

</body>

</html>