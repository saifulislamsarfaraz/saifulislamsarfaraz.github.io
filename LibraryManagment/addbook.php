<?php 
   require 'includes/snippet.php';
   require 'includes/db-inc.php';
   include "includes/header.php";
   
   if(isset($_POST['submit'])){
   
       $title = sanitize(trim($_POST['title']));
       $author = sanitize(trim($_POST['author']));
       $label = sanitize(trim($_POST['label']));
       $publisher = sanitize(trim($_POST['publisher']));
       $category = sanitize(trim($_POST['category']));
       $call = sanitize(trim($_POST['call']));
   
   $sql = "INSERT INTO books(bookTitle, author, ISBN, publisherName, categories, callNumber)
                    values ('$title','$author','$label', '$publisher','$category','$call')";
   
       $query = mysqli_query($conn, $sql);
   
       if($query){
           echo "<script>alert('New Book has been added ');
                    location.href ='bookstable.php';
                    </script>";
       }
       else {
           echo "<script>alert('Book not added!');
                    </script>"; 
       }
   
   }
   
   ?>
<div class="container">
<?php include "includes/nav.php"; ?>
<div class="container  col-lg-9 col-md-11 col-sm-12 col-xs-12 col-lg-offset-2 col-md-offset-1 col-sm-offset-0 col-xs-offset-0  " style="margin-top: 20px">
   <div class="jumbotron login2 col-lg-10 col-md-11 col-sm-12 col-xs-12">
      <p class="page-header" style="text-align: center">ADD BOOK</p>
      <div class="container">
         <form class="form-horizontal" role="form" enctype="multipart/form-data" action="addbook.php" method="post">
            <div class="form-group">
               <label for="Title" class="col-sm-2 control-label">BOOK TITLE</label>
               <div class="col-sm-10">
                  <input type="text" class="form-control" name="title" placeholder="Enter Title" id="password" required>
               </div>
            </div>
            <div class="form-group">
               <label for="Author" class="col-sm-2 control-label">AUTHOR</label>
               <div class="col-sm-10">
                  <input type="text" class="form-control" name="author" placeholder="Enter Author" id="password" required>
               </div>
            </div>
            <div class="form-group">
               <label for="ISBN" class="col-sm-2 control-label">ISBN</label>
               <div class="col-sm-10">
                  <input type="text" class="form-control" name="label" placeholder="Enter ISBN" id="password" required>
               </div>
            </div>
            <div class="form-group">
               <label for="Publisher" class="col-sm-2 control-label">PUBLISHER</label>
               <div class="col-sm-10">
                  <input type="text" class="form-control" name="publisher" placeholder="Enter Publisher" id="password" required>
               </div>
            </div>
            <div class="form-group">
               <label for="Publisher" class="col-sm-2 control-label">CATEGORY</label>
               <div class="col-sm-10">
                  <input type="text" class="form-control" name="category" placeholder="Enter Category" id="password" required>
               </div>
            </div>
            <div class="form-group">
               <label for="Publisher" class="col-sm-2 control-label">CALL NUMBER</label>
               <div class="col-sm-10">
                  <input type="text" class="form-control" name="call" placeholder="call number" id="password" required>
               </div>
            </div>
            <div class="form-group">
               <div class="col-sm-offset-2 col-sm-10">
                  <button  name="submit" class="btn btn-info col-lg-12" data-toggle="modal" data-target="#info">
                  ADD BOOK
                  </button>
               </div>
            </div>
         </form>
      </div>
   </div>
</div>
<script type="text/javascript" src="js/jquery.js"></script>
<script type="text/javascript" src="js/bootstrap.js"></script>
</body>
</html>