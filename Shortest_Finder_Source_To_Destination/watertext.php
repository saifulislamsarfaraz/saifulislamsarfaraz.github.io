<style>
.loader{
    background: #2C3531;
    justify-content: center;
	position: relative;
    text-align: right;
	top: 7%;
	left: 50%;
	border-radius: 20px;
	-webkit-transform: translate(-50%,-50%);
	   -moz-transform: translate(-50%,-50%);
	    -ms-transform: translate(-50%,-50%);
	     -o-transform: translate(-50%,-50%);
	        transform: translate(-50%,-50%);
}

.loader h1{
    background-color: #FFFAFA;
    text-align: center;
	padding: 0;
	text-transform: uppercase;
	margin: 15px;
	font-size: 6em;
	color: rgba(255,255,255,.1);
	background-image: url(https://image.ibb.co/ciSeac/image.png);
	background-repeat: repeat-x;
	-webkit-background-clip: text;
	animation: animate 10s linear infinite;

}
.loader h5{
	justify-content: center;
	background-color: white;
}
@keyframes animate{
	0%{
		background-position: left 0px top 80px;
	}
	10%{
		background-position: left 2400px top -60px;
	}
	20%{
		background-position: left 400px top -50px;
	}
	40%{
		background-position: left 600px top -50px;
	}
	60%{
		background-position: left 800px top -50px;
	}
	80%{
		background-position: left 1000px top -50px;
	}
	100%{
		background-position: left 2400px top -40px;
	}
}

</style>


<div class="loader">
<h1>Shortest path finder</h1>
</div>


