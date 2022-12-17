<?php

include '_dbconnect.php';
$insertsuccess = false;
$errmsg = 'noerror';

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $username = $_POST['username'];
    $password = $_POST['password'];
    $conpass = $_POST['conpassword'];

    $userexist = false;
    $uexistsql = "SELECT * FROM `users` WHERE `username` ='$username'";
    $result = $conn->query($uexistsql);
    if ($result->num_rows > 0) {
        $userexist = true;
    }

    if (($password == $conpass) && ($userexist == false)) {
        $passwordhash = password_hash($password, PASSWORD_DEFAULT);
        $insertusersql = "INSERT INTO `users`(`username`,`password`,`user_added`) VALUES ('$username', '$passwordhash', current_timestamp());";
        $insertuserresult = $conn->query($insertusersql);
        if ($insertuserresult) {
            $insertsuccess = true;
            header("location: /myapp/myforum/index.php?signupsuccess=true");
        }
    } elseif ($userexist == true) {
        $errmsg = 'This username is not available. Try another.';
        header("location: /myapp/myforum/index.php?signupsuccess=false&errmsg=$errmsg");
    } else {
        $errmsg = 'Password do not match';
        header("location: /myapp/myforum/index.php?signupsuccess=false&errmsg=$errmsg");
    }
}
