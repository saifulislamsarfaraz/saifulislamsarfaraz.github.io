<?php
   session_start(); 
   // session_destroy();
   if (!(isset($_SESSION['auth']) && $_SESSION['auth'] === true)) {
   	header("Location: index.php");
   	exit();
   }
   else {
    	$admin = $_SESSION['admin'];
   }
   require 'includes/db-inc.php';
   include "includes/header.php";
   
   ?>
<!DOCTYPE html>
<html>
   <head>
      <title>Admin Home</title>
   </head>
   <body>
      <div class="container">
         <?php include "includes/nav.php"; ?>
         <!-- navbar ends -->
         <!-- info alert -->
         <div class="alert alert-warning col-lg-7 col-md-12 col-sm-12 col-xs-12 col-lg-offset-2 col-md-offset-0 col-sm-offset-1 col-xs-offset-0" style="margin-top:70px">
            <h4 class="center-block"><strong>ADMIN DASHBOARD</strong> </h4>
         </div>
         <div class="row">
            <a href="bookstable.php"><button class="btn btn-success col-lg-3 col-md-4 col-sm-11 col-xs-11 button" style="margin-left: 15px;margin-bottom: 5px"><span class="glyphicon"></span> All Books </button></a>
            <a href="viewstudents.php"><button class="btn btn-success col-lg-3 col-md-4 col-sm-11 col-xs-11 button" style="margin-left: 15px;margin-bottom: 5px"><span class="glyphicon"></span> Students List</button></a>
            <a href="borrowedbooks.php"><button class="btn btn-success col-lg-3 col-md-4 col-sm-11 col-xs-11 button" style="margin-left: 15px;margin-bottom: 5px"><span class="glyphicon"></span> Borrowed Books</button></a>      
         </div>
      </div>
      </div>
      <script type="text/javascript" src="js/jquery.js"></script>
      <script type="text/javascript" src="js/bootstrap.js"></script>	
   </body>
</html>