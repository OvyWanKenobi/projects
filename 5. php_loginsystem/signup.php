<?php

session_start();
if ((isset($_SESSION['loggedin'])) && $_SESSION['loggedin'] == true) {
    header("location:welcome.php");
}


$insertsuccess = false;
$errmsg = 'noerror';
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    include 'partials/_dbconnect.php';
    $username = $_POST['username'];
    $password = $_POST['password'];
    $conpass = $_POST['conpassword'];

    //check if user exist
    $userexist = false;
    $uexistsql = "SELECT * FROM `users` WHERE username = '$username'";
    $result = $conn->query($uexistsql);
    if ($result->num_rows > 0) {
        $userexist = true;
    }

    if (($password == $conpass) && ($userexist == false)) {

        $hash = password_hash($password, PASSWORD_DEFAULT);
        $insertsql = "INSERT INTO `users` (`username`, `password`, `datetime`) VALUES ('$username', '$hash', current_timestamp());";
        $insertresult = $conn->query($insertsql);
        if ($insertresult) {
            $insertsuccess = true;
        }
    } elseif ($userexist == true) {
        $errmsg = 'This username is not available. Try another.';
    } else {
        $errmsg = 'Password do not match';
    }
}

?>




<!doctype html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Sign Up</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65" crossorigin="anonymous">
</head>

<body>
    <?php
    require 'partials/_nav.php';
    ?>

    <?php
    if ($insertsuccess) {
        echo '
    <div class="alert alert-success alert-dismissible fade show" role="alert">
        <strong>Success!</strong> Your Sign up was successful
        <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
    </div>
    ';
    } elseif ($errmsg != 'noerror') {
        echo '
         <div class="alert alert-danger alert-dismissible fade show" role="alert">
        <strong>Error!</strong> ' . $errmsg . ' 
        <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
    </div>
        ';
    }


    ?>


    <div class="container my-4">
        <h1 class="text-center mt-3">Sign up</h1>


        <form action="/myapp/loginsystem/signup.php" method="post" class="d-flex flex-column align-items-center">
            <div class=" mb-3 col-8 ">
                <label for=" username" class="form-label">Username</label>
                <input type="text" class="form-control" id="username" name="username" maxlength="20">
            </div>
            <div class="mb-3 col-8">
                <label for="password" class="form-label">Password</label>
                <input type="password" class="form-control" id="password" name="password" maxlength="15">
            </div>
            <div class="mb-3 col-8">
                <label for="conpassword" class="form-label">Confirm Password</label>
                <input type="password" class="form-control" id="conpassword" name="conpassword" aria-describedby=" conpassword" maxlength="15">
                <div id="conpassword" class="form-text">Please make sure you type the same password</div>
            </div>
            <button type="submit" class="btn btn-primary col-8">Submit</button>
        </form>

    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-kenU1KFdBIe4zVF0s0G1M5b4hcpxyD9F7jL+jjXkk+Q2h455rYXK/7HAuoJl+0I4" crossorigin="anonymous"></script>
</body>

</html>