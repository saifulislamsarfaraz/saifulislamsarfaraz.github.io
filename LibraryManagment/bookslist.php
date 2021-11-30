<?php 
    include "includes/header.php"; 
    include "includes/db-inc.php"; 

?>

<div class="container">
   <!-- navbar ends -->
   <!-- info alert -->
   <div class="alert alert-warning col-lg-7 col-md-12 col-sm-12 col-xs-12 col-lg-offset-2 col-md-offset-0 col-sm-offset-1 col-xs-offset-0" style="margin-top:70px">
      <span class="glyphicon glyphicon-book"></span>
      <strong>List of Books in the Library</strong>
   </div>
</div>
<div class="container">
   <div class="row">
            <a href="index.php"><button class="btn btn-success col-lg-3 col-md-4 col-sm-11 col-xs-11 button" style="margin-left: 15px;margin-bottom: 5px"><span class="glyphicon glyphicon-home"></span>&nbsp&nbspHOME</button></a>
   </div>

   <div class="panel panel-default">
      <table class="table table-bordered">
         <thead>
            <tr>
               <th>BookId</th>
               <th>bookTitle</th>
               <th>author</th>
               <th>ISBN</th>
               <th>publisherName</th>
               <th>categories</th>
               <th>callNumber</th>
            </tr>
         </thead>
         <?php 
            $sql = "SELECT * from books";
            
            $query = mysqli_query($conn, $sql); 
            $counter = 1;
            while ($row = mysqli_fetch_array($query)) { ?>
         <tbody>
            <td><?php echo $row['bookId']; ?></td>
            <td><?php echo $row['bookTitle']; ?></td>
            <td><?php echo $row['author']; ?></td>
            <td><?php echo $row['ISBN']; ?></td>
            <td><?php echo $row['publisherName']; ?></td>
            <td><?php echo $row['categories']; ?></td>
            <td><?php echo $row['callNumber']; ?></td>
         </tbody>
         <?php 	}
            ?>
      </table>
   </div>
</div>
<script type="text/javascript" src="js/jquery.js"></script>
<script type="text/javascript" src="js/bootstrap.js"></script>	
</body>
</html>