<style type="text/css">
    .normal,.road,.home,.visit,.visit_previous{
        width: 29px;
        height: 29px;
        margin-top: 5px;
        float: left;
        color: #000000;
        font-size: 10px;
        text-align: center;
        justify-content: center;
    }
    .home{
        background-color: #a10a50;
    }
    .market{
        background-color: #071752;
    }
    .normal{
        background: url(File/);
        background-size: cover;
    }
    .btn{
        width: 100%;
        height: 100%;
        cursor: pointer;
    }
    .visit{
        background: url(File/map.png);
        background-size: 100%;
        transition: all .2s ease-in;
        filter: contrast(200%);
    }

    .visit_previous{
        background: url(File/);
        background-size: cover;
        transition: all 0.2s ease-in;
        filter: brightness(20%);
        filter: invert(100%);
    }

    .header{
        width: 1440px;
        height: 635px;
        position: relative;
    }
</style>

<?php include("watertext.php");?>

<div class="header">
    <?php 
    function set_home($x,$y,$home){
        $mark = $home;
        $mark[$x][$y] = 1;
        $mark[$x+1][$y+1] = 1;
        $mark[$x-1][$y-1] = 1;
        $mark[$x+1][$y-1] = 1;
        $mark[$x-1][$y+1] = 1;
        $mark[$x+1][$y] = 1;
        $mark[$x][$y+1] = 1;
        $mark[$x-1][$y] = 1;
        $mark[$x][$y-1] = 1;
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
    for($i = 0; $i < 50; $i++){
        for($j = 0; $j < 50; $j++){
            $home[$i][$j] = 0;
            $market[$i][$j] = 0;
            $road[$i][$j] = 0;
            $center[$i][$j] = 0;
        }
    }
    $home = set_home(5,7,$home);

    $market_vertext_x = array(5,5,5,11,18,18,18,18,4,11,18);
    $market_vertext_y = array(19,31,42,25,7,19,31,42,25,4,25);

    
    for($i = 0; $i < 11; $i++){
        $x = $market_vertext_x[$i];
        $y = $market_vertext_y[$i];
        $market = set_home($a,$b,$market);
        $road = set_market_road($a,$b,$road);
        $center[$a][$b] = 1;
    }
    $road = set_road(1,1,"v_l",46,$road);//horizontal
    $road = set_road(8,1,"v_l",46,$road);
    $road = set_road(15,1,"v_l",46,$road);
    $road = set_road(21,1,"v_l",46,$road);

    $road = set_road(1,1,"v_u",20,$road);//vertical
    $road = set_road(1,13,"v_u",7,$road);
    $road = set_road(1,37,"v_u",7,$road);
    $road = set_road(1,47,"v_u",20,$road);

    $road = set_road(8,34,"v_u",7,$road);
    $road = set_road(8,16,"v_u",7,$road);




?>

</div>