<?php
include '_dbconnect.php';
$loggedin = false;
if ((isset($_SESSION['loggedin'])) && $_SESSION['loggedin'] == true) {
    $loggedin = true;
    $loggeduser = $_SESSION['loggeduser'];
}


echo '
<nav class="navbar navbar-expand-lg bg-dark navbar-dark navbar-fixed-top">
    <div class="container-fluid">
    ';
if ($loggedin == true) {
    echo '
        <a class="navbar-brand" href="index.php">myForum</a>
    ';
}

if ($loggedin == false) {
    echo '
        <a class="navbar-brand" href="index.php">myForum</a>
    ';
}
echo '
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarSupportedContent">
          
             
        ';
if ($loggedin == true) {


    echo '
             <ul class="navbar-nav me-auto mb-2 mb-lg-0">
                <li class="nav-item">
                    <a class="nav-link" aria-current="page" href="index.php">Home</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="about.php">About</a>
                </li>
                 <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                        Catagories
                    </a>
                    <ul class="dropdown-menu">';
    $sql = "SELECT cat_title, cat_id FROM  `catagories` ";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            echo '
                        <li><a class="dropdown-item" href="threadlist.php?cat_id=' . $row['cat_id'] . '">' . $row['cat_title'] . '</a></li>';
        }
    }


    echo '
                       
                    </ul>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="contact.php">Contact</a>
                </li>
                

            </ul>
           
            <form class="d-flex" role="search" action="search.php" method="get">
                <input class="form-control mx-1" type="search" name="search" placeholder="Search" aria-label="Search">
                <button class="btn btn-outline-primary me-1" type="submit">Search</button>
             </form>
            <div ><p class="text-white navbar-nav mx-2">Welcome, ' . $loggeduser . '</p></div>
            <ul class="navbar-nav mx-2 ">
                 <li class="nav-item">
                    <a class="text-white nav-link btn btn-danger mx-2 " href="logout.php">Logout</a>
                </li>

             </ul>
            

            ';
}


if ($loggedin == false) {

    echo
    '
            <ul class="navbar-nav me-auto mb-2 mb-lg-0">
                <li class="nav-item">
                    <a class="nav-link" href="about.php">About</a>
                </li>
                  <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                        Catagories
                    </a>
                    <ul class="dropdown-menu">';
    $sql = "SELECT cat_title, cat_id FROM  `catagories` ";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            echo '
                        <li><a class="dropdown-item" href="threadlist.php?cat_id=' . $row['cat_id'] . '">' . $row['cat_title'] . '</a></li>';
        }
    }


    echo '
                       
                    </ul>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="contact.php">Contact</a>
                </li>

             </ul>
           
            <form class="d-flex" role="search" action="search.php" method="get">
                <input class="form-control mx-1" type="search" name="search" placeholder="Search" aria-label="Search">
                <button class="btn btn-outline-light me-1" type="submit">Search</button>
             </form>
             <div class="d-flex justify-content-center my-md-0 my-2">
             <button type="button" class="btn btn-success  ms-2" data-bs-toggle="modal" data-bs-target="#loginmodal">
                LOGIN
            </button>
            <button type="button" class="btn btn-success mx-1" data-bs-toggle="modal" data-bs-target="#signupmodal">
                SIGNUP
            </button>
           </div>
               ';
}

echo '

        </div>
    </div>
</nav>

';

include 'partials/_loginmodal.php';
include 'partials/_signupmodal.php';

if (isset($_GET['signupsuccess']) && $_GET['signupsuccess'] == 'true') {
    echo '
                <div class="alert alert-success alert-dismissible fade show" role="alert">
                <strong>Success!</strong> You have successfully created an account.
                <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
                </div>
                ';
} elseif (isset($_GET['signupsuccess']) && $_GET['signupsuccess'] == 'false') {
    echo '
                <div class="alert alert-danger alert-dismissible fade show" role="alert">
                <strong>Sorry!</strong>' . $_GET['errmsg'] . '
                <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
                </div>
                ';
}

if (isset($_GET['loginsuccess']) && $_GET['loginsuccess'] == 'true') {
    echo '
                <div class="alert alert-success alert-dismissible fade show" role="alert">
                <strong>Success!</strong> You have successfully loggedin.
                <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
                </div>
                ';
} elseif (isset($_GET['loginsuccess']) && $_GET['loginsuccess'] == 'false') {
    echo '
                <div class="alert alert-danger alert-dismissible fade show" role="alert">
                <strong>Sorry!</strong>' . $_GET['errmsg'] . '
                <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
                </div>
                ';
}
