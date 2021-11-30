<?php
	require_once 'includes/db-inc.php';
	
	if($_GET['bookId']){
		$bookId = $_GET['bookId'];
		
		$conn->query("DELETE FROM `borrow` WHERE `bookId` = $bookId") or die(mysqli_errno());
		header("location: borrowedbooks.php");
	}	
?>