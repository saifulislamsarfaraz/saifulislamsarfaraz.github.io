<?php 
   require 'includes/snippet.php';
   require 'includes/db-inc.php';
   include "includes/header.php"; 
   
   
   
   	
   if(isset($_POST['submit'])){
   	$studentId = trim($_POST['studentID']);
   	$bdate = trim($_POST['borrowDate']);
   	$due = trim($_POST['dueDate']);
   	$bookId = trim($_POST['bookId']);
   
   	
   
   	$sql = "INSERT INTO borrow (studentId, bookId, borrowDate, returnDate) values('$studentId','$bookId', '$bdate', '$due')";
   	$query = mysqli_query($conn, $sql);
   
   	if($query){
   
   		echo "
   			<script type = 'text/javascript'>
            
                  alert ('Success');
                  document.write ('');
             
         </script>    ";
   			header("Location: borrowedbooks.php");
   
   
   	}
   	else {
   		echo "
   		<script>
   		alert('Unsuccessful');
   		</script>
   	";
   	}
   
   }
   	
   ?>
<div class="container">
   <?php include "includes/nav.php"; ?>
   <div class="container  col-lg-9 col-md-11 col-sm-12 col-xs-12 col-lg-offset-2 col-md-offset-1 col-sm-offset-0 col-xs-offset-0  " style="margin-top: 30px">
      <div class="jumbotron login col-lg-10 col-md-11 col-sm-12 col-xs-12">
         <p class="page-header" style="text-align: center">LEND BOOK</p>
         <div class="container">
            <form class="form-horizontal" role="form" action="#" method="post" enctype="multipart/form-data">
               <div class="form-group">
                  <label for="Book ID" class="col-sm-2 control-label">Book ID</label>
                  <div class="col-sm-10">
                     <input type="text" class="form-control" name="bookId" id="bookId" value="<?php ?>">
                  </div>
               </div>
               <div class="form-group">
                  <label for="Student ID" class="col-sm-2 control-label">Student ID</label>
                  <div class="col-sm-10">
                     <input type="text" class="form-control" name="studentID" value="<?php ?>">
                  </div>
               </div>
               <div class="form-group">
                  <label for="Borrow Date" class="col-sm-2 control-label">BORROW DATE</label>
                  <div class="col-sm-10">
                     <input type="date" class="form-control" name="borrowDate" id="brand">
                  </div>
               </div>
               <div class="form-group">
                  <label for="Password" class="col-sm-2 control-label">RETURN DATE</label>
                  <div class="col-sm-10" id="show_product">
                     <input type='date' class='form-control' name='dueDate'>
                  </div>
               </div>
               <div class="form-group ">
                  <div class="col-sm-offset-2 col-sm-10 ">
                     <button type="submit" class="btn btn-info col-lg-4 " name="submit">
                     Submit
                     </button>
                  </div>
               </div>
            </form>
         </div>
      </div>
   </div>
</div>
<script type="text/javascript" src="js/jquery.js"></script>
<script type="text/javascript" src="js/bootstrap.js"></script>
</body>
</html>