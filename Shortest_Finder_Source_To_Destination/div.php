<style type="text/css">
 

</style>
<style>
.loader{
    background: #262626;
    justify-content: center;
	position: relative;
    text-align: right;
	top: 10%;
	left: 50%;
	-webkit-transform: translate(-50%,-50%);
	   -moz-transform: translate(-50%,-50%);
	    -ms-transform: translate(-50%,-50%);
	     -o-transform: translate(-50%,-50%);
	        transform: translate(-50%,-50%);
}

.loader h1{
    background-color: #fff;
    text-align: center;
	margin-left: 100px;
	padding: 0;
	text-transform: uppercase;
	font-size: 6em;
	color: rgba(255,255,255,.1);
	background-image: url(https://image.ibb.co/ciSeac/image.png);
	background-repeat: repeat-x;
	-webkit-background-clip: text;
	animation: animate 15s linear infinite;

}

@keyframes animate{
	0%{
		background-position: left 0px top 80px;
	}
	40%{
		background-position: left 800px top -50px;
	}
	80%{
		background-position: left 1800px top -50px;
	}
	100%{
		background-position: left 2400px top 80px;
	}
}

</style>

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