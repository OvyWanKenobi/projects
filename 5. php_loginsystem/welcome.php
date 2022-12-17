<?php
session_start();
if ((!isset($_SESSION['loggedin'])) || $_SESSION['loggedin'] != true) {
    header("location:login.php");
    exit;
}


?>

<!doctype html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Welcome, <?php echo $_SESSION['loggeduser']; ?></title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65" crossorigin="anonymous">
</head>

<body>
    <?php
    require 'partials/_nav.php';
    ?>



    <div class="container my-2">
        <div class="alert alert-success" role="alert">
            <h3 class="alert-heading">Welcome , <?php echo $_SESSION['loggeduser']; ?></h3>
            <p>You have successfully logged in. </p>
            <hr>
            <p class="mb-0">If you need to logout, <a href="/myapp/loginsystem/logout.php">click this link</a></p>
        </div>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-kenU1KFdBIe4zVF0s0G1M5b4hcpxyD9F7jL+jjXkk+Q2h455rYXK/7HAuoJl+0I4" crossorigin="anonymous"></script>
</body>

</html>