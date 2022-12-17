<?php
session_start();
if ((isset($_SESSION['loggedin'])) && $_SESSION['loggedin'] == true) {
    header("location:index.php");
}



$loginsuccess = false;
$errmsg = 'noerror';
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    include 'partials/_dbconnect.php';
    $username = $_POST['username'];
    $password = $_POST['password'];

    $userexists = false;




    $sql = "SELECT * from `users` where username='$username' ";
    $result = $conn->query($sql);
    $resultnum = $result->num_rows;
    if ($resultnum == 1) {
        while ($row = $result->fetch_assoc()) {
            if (password_verify($password, $row['password'])) {
                $loginsuccess = true;
                session_start();
                $_SESSION['loggedin'] = true;
                $_SESSION['loggeduser'] = $username;
                header("location:index.php");
            } else {
                $errmsg = 'Invalid Credentials';
            }
        }
    } else {
        $errmsg = 'Invalid Credentials';
    }
}

?>


<!doctype html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>LogIn</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65" crossorigin="anonymous">
</head>

<body>
    <?php
    require 'partials/_header.php';
    ?>

    <?php
    if ($loginsuccess) {
        echo '
    <div class="alert alert-success alert-dismissible fade show" role="alert">
        <strong>Success!</strong> Your are logged in!
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
        <h1 class="text-center mt-3">Log In</h1>


        <form action="/myapp/myforum/login.php" method="post" class="d-flex flex-column align-items-center">
            <div class=" mb-3 col-8 ">
                <label for=" username" class="form-label">Username</label>
                <input type="text" class="form-control" id="username" name="username">
            </div>
            <div class="mb-3 col-8">
                <label for="password" class="form-label">Password</label>
                <input type="password" class="form-control" id="password" name="password">
            </div>

            <button type="submit" class="btn btn-primary col-8">Submit</button>
        </form>
    </div>
    <?php
    require 'partials/_footer.php';
    ?>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-kenU1KFdBIe4zVF0s0G1M5b4hcpxyD9F7jL+jjXkk+Q2h455rYXK/7HAuoJl+0I4" crossorigin="anonymous"></script>
</body>

</html>