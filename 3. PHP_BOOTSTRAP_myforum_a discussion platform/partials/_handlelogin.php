<?php

include '_dbconnect.php';

$errmsg = 'noerror';
$loginsuccess = false;

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $username = $_POST['username'];
    $password = $_POST['password'];


    $sql = "SELECT * FROM `users` WHERE `username` ='$username'";
    $result = $conn->query($sql);
    if ($result->num_rows == 1) {
        while ($row = $result->fetch_assoc()) {
            if (password_verify($password, $row['password'])) {
                $loginsuccess = true;
                session_start();
                $_SESSION['loggedin'] = true;
                $_SESSION['loggeduser'] = $username;
                $_SESSION['loggeduser_id'] = $row['user_id'];
                header("location:/myapp/myforum/index.php?loginsuccess=true");
            } else {
                $errmsg = 'Invalid Credentials';
                header("location: /myapp/myforum/index.php?loginsuccess=false&errmsg=$errmsg");
            }
        }
    } else {
        $errmsg = 'Invalid Credentials';
        header("location: /myapp/myforum/index.php?loginsuccess=false&errmsg=$errmsg");
    }
}
