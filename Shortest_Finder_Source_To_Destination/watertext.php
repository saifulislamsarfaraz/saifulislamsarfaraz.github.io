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
	padding: 0;
	text-transform: uppercase;
	font-size: 6em;
	color: rgba(255,255,255,.1);
	background-image: url(https://image.ibb.co/ciSeac/image.png);
	background-repeat: repeat-x;
	-webkit-background-clip: text;
	animation: animate 10s linear infinite;

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


<div class="loader">
<h1>Shortest path find</h1>
<?php 
    echo"developed by saifulislamsarfaraz"
?>
</div>


