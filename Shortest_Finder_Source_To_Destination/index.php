<style type="text/css">
    .normal,.road,.market,.home,.visit,.visit_previous{
        width: 12px; 
        height: 12px; 
        margin: 0px;
        float: left;
        color:#000000;
        font-size: 10px;
        text-align: center;
    }
    .home{
       border-radius: 1px; 
       background-color:#b8baba;
    }
    
    .market{
        background-color: red;
    }
    .road{
        background: url(File/road.gif);
        background-size: cover;
        
    }
    .normal{
        background: url(File/tree.png);
        background-size: cover;
    }

    .btn1{
        width: 100%;
        height: 100%;
        cursor: pointer;
        
    }
    .btn1:hover{
        border-radius: 0px;
        background-color: black;
    }
    .tooltiptext {
  visibility: hidden;
  width: 120px;
  background-color: black;
  color: #fff;
  text-align: center;
  border-radius: 6px;
  padding: 5px 0;
  
  /* Position the tooltip */
  position: absolute;
  z-index: 1;
  bottom: 100%;
  left: 50%;
  margin-left: -60px;
   }
    .btn1:hover.tooltiptext {
    visibility: visible;
   }
    .visit{
        background: url(File/map.png);
        background-size: 100%;
        transition: all 0.000009s ease-in;
        filter: contrast(200%);
        background-color: green;
    }

    .visit_previous{
        background: url(File/map.png);
        background-size: cover;
        transition: all 0.02s ease-in;
        filter: brightness(100%);
        background-color: yellow;
    }

    .header{
        width: 588px;
        height: 863px;
        position: absolute;
    }
</style>

<span class="tooltiptext">Click Button</span>
<div class="header">
    <?php 
    function set_home($x,$y,$home){
        $mark = $home;
        $mark[$x][$y]=1;
        $mark[$x+1][$y+1]=1;
        $mark[$x-1][$y+1]=1;
        $mark[$x+1][$y-1]=1;
        $mark[$x-1][$y-1]=1;
        $mark[$x+1][$y]=1;
        $mark[$x-1][$y]=1;
        $mark[$x][$y+1]=1;
        $mark[$x][$y-1]=1;
    return $mark;
    }
    function set_market_road($x,$y,$road){
        $mark = $road;
        $mark[$x][$y] = 1;
        $mark[$x+1][$y] = 1;
        $mark[$x-1][$y] = 1;
        $mark[$x][$y+1] = 1;
        $mark[$x][$y-1] = 1;
        return $mark;
    }

    function set_road($x,$y,$vertex,$limit,$road){
        if($vertex=="v_l"){
            for($i=$y; $i<=$y+$limit;$i++){
                $road[$x][$i] = 1;
            }
        }else if($vertex=="v_u"){
            for($i=$x; $i<=$x+$limit; $i++){
                $road[$i][$y] = 1;
            }
        }
        return $road;
    }
    ?>
<?php

    for($i=0; $i<50; $i++){
        for($j=0; $j<50; $j++){
        $home[$i][$j]=0;
        $market[$i][$j]=0;
        $road[$i][$j]=0;
        $center[$i][$j]=0;
        }
    }
    $home = set_home(5,7,$home);

    $market_vertext_x = array(5,5,5,5,11,18,18,18,18,4,11,18,11,25,25,25,25,25,25,35,33,35,34,35,34,42,43,42,42,41,42);
    $market_vertext_y = array(7,19,31,42,25,7,19,31,42,25,4,25,42,7,19,13,30,36,42,6,13,20,30,36,42,7,14,20,30,36,42);

    
    for($i = 0; $i < 31; $i++){
        $x = $market_vertext_x[$i];
        $y = $market_vertext_y[$i];
        $market = set_home($x,$y,$market);
        $road = set_market_road($x,$y,$road);
        $center[$x][$y] = 1;
    }
    
$road=set_road(8,1,'v_l',46,$road);
$road=set_road(15,1,'v_l',46,$road);
$road=set_road(1,1,'v_l',46,$road);
$road=set_road(21,1,'v_l',46,$road);
$road=set_road(47,1,'v_l',46,$road);
$road=set_road(30,1,'v_l',46,$road);
$road=set_road(38,1,'v_l',46,$road);
$road=set_road(25,1,'v_l',5,$road);
$road=set_road(25,19,'v_l',5,$road);


$road=set_road(1,1,'v_u',46,$road);
$road=set_road(1,47,'v_u',46,$road);
$road=set_road(1,37,'v_u',7,$road);
$road=set_road(1,13,'v_u',7,$road);
$road=set_road(22,25,'v_u',24,$road);
$road=set_road(27,13,'v_u',3,$road);


$road=set_road(8,34,'v_u',7,$road);
$road=set_road(8,16,'v_u',7,$road);

$road=set_road(15,13,'v_u',5,$road);
$road=set_road(15,37,'v_u',5,$road);

$road=set_road(6,19,'v_u',1,$road);
$road=set_road(6,31,'v_u',1,$road);
$road=set_road(6,42,'v_u',1,$road);

$road=set_road(9,25,'v_u',1,$road);

$road=set_road(16,42,'v_u',1,$road);
$road=set_road(16,31,'v_u',1,$road);
$road=set_road(16,19,'v_u',1,$road);
$road=set_road(16,7,'v_u',3,$road);



$road=set_road(5,2,'v_l',3,$road);
$road=set_road(5,9,'v_l',3,$road);

$road=set_road(5,7,'v_u',2,$road);
$road=set_road(2,25,'v_u',1,$road);
$road=set_road(9,4,'v_u',1,$road);

$road=set_road(19,25,'v_u',1,$road);
$road=set_road(27,19,'v_u',2,$road);
$road=set_road(21,7,'v_u',3,$road);

$road=set_road(9,42,'v_u',1,$road);
$road=set_road(1,7,'v_u',3,$road);



for($i=0; $i<49; $i++){

    for($j=0; $j<49; $j++){
    
    $btn="";
    $onclick="";
    $val=0;
    
    if($road[$i][$j]==1){
        $class="road";
        if($home[$i][$j]==1)$class="home";
        if($market[$i][$j]==1)$class="market";
        $val=1;
    }
    else if($home[$i][$j]==1){
        $class="home";
    }
    else if($market[$i][$j]==1){
        $class="market";
    }    
    
    else $class="normal";
    
    if($center[$i][$j]==1){
        $btn="<button class='btn1'></button>";
        $onclick="onclick='fun($i,$j)'";
    }
    
    $div_id=$i.",".$j;
     echo "<input type='text' name='' id='road_$div_id' value='$val' hidden>";
     echo "<input type='text' name='' id='s_x' value='-1' hidden>";
     echo "<input type='text' name='' id='s_y' value='-1' hidden>";
    
    $animation="";
    if($class=="road"){
      $animation="<div class='dot'></div>";
    }
    
     echo "<div id='$div_id' $onclick class='$class' >$btn</div>";
    ?>
    
    <?php } } ?>
    
    </div>
    
