<?php 
require 'includes/snippet.php';
require 'includes/db-inc.php';
include "includes/header.php"; 

	if (isset($_POST['submit'])) {
		$id = trim($_POST['del_btn']);
		$sql = "DELETE from students where studentId = '$id'";
		$query = mysqli_query($conn, $sql);

		if ($query) {
			echo "<script>alert('Student Deleted!')</script>";
		}
	}

?>


<div class="container">
    <?php include "includes/nav.php"; ?>
	<!-- navbar ends -->
	<!-- info alert -->
	<div class="alert alert-warning col-lg-7 col-md-12 col-sm-12 col-xs-12 col-lg-offset-2 col-md-offset-0 col-sm-offset-1 col-xs-offset-0" style="margin-top:70px">

		<span class="glyphicon glyphicon-book"></span>
	    <strong>Student</strong> Table
	</div>


	</div>
	<div class="container col-lg-11 ">
		<div class="panel panel-default">
		  <!-- Default panel contents -->
		  <div class="panel-heading">
		  	<div class="row">
		  	  <a href="addstudent.php"><button class="btn btn-success col-lg-3 col-md-4 col-sm-11 col-xs-11 button" style="margin-left: 15px;margin-bottom: 5px"><span class="glyphicon glyphicon-plus-sign"></span> Add Student</button></a>
			  
			</div>
		  </div>
		  <table class="table table-bordered">
		          <thead>
		               <tr>
		               	  <th>#</th> 
		                  <th>ID No</th>
		                  <th>Name</th>
		                  <th>Email</th>
		                  <th>Department</th>
		                  <th>Phone No.</th>		             
		                  <th>REMOVE</th>
		                </tr>    
		          </thead>    
		          <?php 

		          $sql = "SELECT * FROM students";
		          $query = mysqli_query($conn, $sql);
		          $counter = 1;
		          while ( $row = mysqli_fetch_assoc($query)) {        	
		           ?>
		          <tbody> 
		            <tr> 
		             <td><?php echo $counter++; ?></td>
		             <td><?php echo $row['studentId']; ?></td>
		             <td><?php echo $row['name']; ?></td>
		             <td><?php echo $row['email']; ?></td>
		             <td><?php echo $row['department']; ?></td>
		             <td><?php echo $row['phoneNumber']; ?></td>
		             
		             <td>
		             	<form action="viewstudents.php" method="post">
		             		<input type="hidden" value="<?php echo $row['studentId']; ?>" name="del_btn">
		             		<button name="submit" class="btn btn-warning">DELETE</button>
		             	</form> 
		         	</td>
		            </tr> 
		           
		         </tbody> 
		         <?php } ?>
		   </table>		 
	  </div>
	</div>
</body>
</html>