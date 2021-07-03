<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<!--
    <form action = "hello.php" method="get">
    Name: <input type="text" name = "name">
    <br><br>
    Age: <input type="number" name = "age">
    <br>
    <br>
    <input type="submit">
    </form>

    <form action="hello.php" method="get">
    Number 1:<input type="number" name="num1">
    <br><br>
    Number 2:<input type="number" name="num2">
    <hr>
    <br>




    <input type="submit">
    </form>    

    
    <form action="hello.php" method="post">
    
    Color: <input type="text" name="color"> <br>
    Plural Noun: <input type="text" name="pluralNoun"> <br>
    Celebrity: <input type="text" name= "celebrity"> <br>

    <input type="submit">
    </form>
   

    <form action="hello.php" method="post">
        Apples: <input type="checkbox" name="fruits[]" value="apples"> <br>
        Mangos: <input type="checkbox" name="fruits[]" value="mangos"> <br>
        Oranges: <input type="checkbox" name="fruits[]" value="oranges"> <br>
        Pears: <input type="checkbox" name="fruits[]" value="pears"> <br>
        
        <input type="submit">

    
    </form>
   -->
    <form action="hello.php" method="post">
    <!--<input type="text" step="0.001" name="num1"> <br>
    <input type="text" name="op"> <br>
    <input type="text" step="0.001" name="num2"> <br>
    <input type="text" name="grade">
    -->


    <input type="submit">
    </form>

    <br><br><br>
    <?php

    $index = 1;
    while($index <= 5){
        echo "$index <br>";
        $index++;
    }

    for($i = 0; $i <= 5; $i++){
        echo "$i <br>";
    }

    $numbers = array(1,2,3,4,5,6,7,8,9);
    
    for($i = 0; $i <= count($numbers); $i++){
        echo "$numbers[$i] <br>";
    }

    $title = "this is your page";
    $author = "saiful";
    $wordCount = 400;
    include "again.php";    
   
    include "useful-tool.php";
    sayHi(" saiful you");

    echo $feetInMile;



    class Book{
        var $title;
        var $author;
        var $pages;

        function __construct($aTitle, $aAuthor,$aPages){
            $this->title = $aTitle;
            $this->author = $aAuthor;
            $this->pages = $aPages;
        }
    }

    $book = new Book("Harry Pottar<br>","JK Rowling<br>",100);

    echo $book->author;











































/*

    $grade = $_POST["grade"];

    switch($grade){
        case "A":
            echo "you did amazing";
            break;
    }















































    $num1 = $_POST["num1"];
    $op = $_POST["op"];
    $num2 = $_POST["num2"];

    if($op=="+"){
        echo $num1 + $num2;
    }else if($op=="-"){
        echo abs($num1 - $num2);
    }else if($op=="*"){
        echo $num1 * $num2;
    }else if($op=="/"){
        echo $num1/$num2;
    }else{
        echo "invalid Oparator";
    }











 

    $fruits = $_POST["fruits"];
    echo $fruits[1];
    $grades = array("Alu"=>"A+","Mula"=>"A-","Dheros"=>"C+");
    echo $grades[$_POST["student"]];
    function sayHi($name){
        echo "hello $name";
    }
    $name = "saiful";
    sayHi($name);
    function cube($num){
        return $num * $num * $num;
    }
    echo $cubeResult = cube(2);

    function getMax($num1, $num2, $num3){
        if($num1>=$num2 && $num1 >= $num3){
            return $num1;
        }else if($num2>=$num1 && $num2 >= $num3){
            return $num2;
        }else{
            return $num3;
        }
    }

     echo getMax(12,35,5);
    


















    //$city = array("dhaka", "khulna", "Bagherhat","Noyakhali", "chandpur");
    //echo $city[0];
    //echo "<br>";
    //echo count($city);
    





















































     
      $color = $_POST["color"];
      $pluralNoun = $_POST["pluralNoun"];
      $celebrity = $_POST["celebrity"];

      echo "Rose are {$color} <br>";
      echo "{$pluralNoun} are blue <br>";
      echo "I love {$celebrity} <br>";





    // echo $_GET["num1"] + $_GET["num2"];
     
     // echo $_GET["name"];
     //echo $_GET["age"];


      //  $characterName = "Robin";
      //  $characterAge = 35;

      //  echo "There once was a man name ${characterName} <br>";
      //  echo "He was ${characterAge} years old <br>";
      //  $characterName = "Saiful";
      $phrase = "saiful";
        echo substr($phrase, 3, 2);
        echo str_replace("ful", "<br>faysal",$phrase);
        echo "<br>";
        //echo $characterName[1];
        //echo strtoupper($characterName);
        //echo " He realy liked the name $characterName <br>";
        //echo "but didnot being like being ${characterAge} <br>";
        echo pow(2,6);
        echo "<br>";
        echo abs((-5654));
        echo "<br>";
        echo sqrt(1445);
    */
    



    



































    ?>

</body>
</html>