<style type="text/css">
 

</style>
<?php include("watertext.php");?>

<div class="header">
    <?php 
    
    function set_road($x,$y,$road){
        $mark = $road;
        $mark[$x][$y] = 1;
        $mark[$x+1][$y] = 1;
        $mark[$x-1][$y] = 1;
        $mark[$x][$y+1] = 1;
        $mark[$x][$y-1] = 1;
        return $mark;
    }

    ?>

</div>