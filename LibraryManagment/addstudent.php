<?php 
   require 'includes/snippet.php';
   require 'includes/db-inc.php';
   include "includes/header.php"; 
   
   if(isset($_POST['submit'])) {
   
       $studentId = sanitize(trim($_POST['studentId']));
       $email = sanitize(trim($_POST['email']));
       $dept = sanitize(trim($_POST['dept']));
       $phone = sanitize(trim($_POST['phone']));
       $name = sanitize(trim($_POST['name']));
   
   
   
         $sql = "INSERT INTO students( studentId, email, department, phoneNumber, name) VALUES ('$studentId',  '$email', '$dept','$phone', '$name' ) ";
   
         $query = mysqli_query($conn, $sql);
         $error = false;
         if($query){
          $error = true;
         }
         else{
           echo "<script>alert('Registration failed!! Try again.');
                       </script>";
         }
        
   
   }
   
   ?>
<div class="container">
   <?php include "includes/nav.php"; ?>
   <div class="container  col-lg-9 col-md-11 col-sm-12 col-xs-12 col-lg-offset-2 col-md-offset-1 col-sm-offset-0 col-xs-offset-0  " style="margin-top: 20px">
      <div class="jumbotron login col-lg-10 col-md-11 col-sm-12 col-xs-10">
         <?php if(isset($error) && $error === true) { ?>
         <div class="alert alert-success alert-dismissable">
            <button type="button" class="close" data-dismiss="alert" aria-hidden="true">&times;</button>
            <strong>Record added Successfully!</strong>
         </div>
         <?php } ?>
         <p class="page-header" style="text-align: center"><b>ADD STUDENT</b></p>
         <div class="container">
            <form class="form-horizontal" role="form" action="addstudent.php" method="post" enctype="multipart/form-data">
               <div class="form-group">
                  <label for="Username" class="col-sm-2 control-label">FULL NAME</label>
                  <div class="col-sm-10">
                     <input type="text" class="form-control" name="name" placeholder="Full Name" id="name" required>
                  </div>
               </div>
               <div class="form-group">
                  <label for="Password" class="col-sm-2 control-label">ID NO</label>
                  <div class="col-sm-10">
                     <input type="text" class="form-control" name="studentId" placeholder="ID Number" id="id_no" required>
                  </div>
               </div>
               <div class="form-group">
                  <label for="Password" class="col-sm-2 control-label">DEPT</label>
                  <div class="col-sm-10">
                     <input type="text" class="form-control" name="dept" placeholder="Department" id="Address" required>
                  </div>
               </div>
               <div class="form-group">
                  <label for="Password" class="col-sm-2 control-label">EMAIL</label>
                  <div class="col-sm-10">
                     <input type="email" class="form-control" name="email" placeholder="Email" id="password" required>
                  </div>
               </div>
               <div class="form-group">
                  <label for="Password" class="col-sm-2 control-label">PHONE NUMBER</label>
                  <div class="col-sm-10">
                     <input type="text" class="form-control" name="phone" placeholder="phone" id="password" required>
                  </div>
               </div>
               <div class="form-group">
                  <div class="col-sm-offset-2 col-sm-10">
                     <button  class="btn btn-info col-lg-12" data-toggle="modal" data-target="#info" name="submit">
                     ADD MEMBER
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