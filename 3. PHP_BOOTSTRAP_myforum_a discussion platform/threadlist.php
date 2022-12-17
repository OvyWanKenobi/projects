<!-- <?php
        session_start();
        if ((!isset($_SESSION['loggedin'])) || $_SESSION['loggedin'] != true) {
        }


        ?> -->



<!doctype html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>MyForum</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65" crossorigin="anonymous">
</head>

<body>
    <?php
    include 'partials/_header.php';
    include 'partials/_dbconnect.php';

    ?>

    <?php
    $cat_id = $_GET['cat_id'];
    $sql = "SELECT * FROM `catagories` WHERE `cat_id`=$cat_id";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            $catname = $row['cat_title'];
            $catdesc = $row['cat_desc'];
        }
    }


    ?>

    <?php
    // echo $_SERVER['REQUEST_METHOD'];
    $threadinsertionalert = false;
    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $newthreadtitle = $_POST['threadtitle'];
        $newthreaddesc = $_POST['threaddesc'];

        $newthreadtitle = str_replace("<", "&lt;", $newthreadtitle); //sanitize, xss attack prevention, if someone use <tag> in inputs 
        $newthreadtitle = str_replace(">", "&gt;", $newthreadtitle); //sanitize, xss attack prevention, if someone use <tag> in inputs

        $newthreaddesc = str_replace("<", "&lt;", $newthreaddesc); //sanitize, xss attack prevention, if someone use <tag> in inputs 
        $newthreaddesc = str_replace(">", "&gt;", $newthreaddesc); //sanitize, xss attack prevention, if someone use <tag> in inputs

        $cat_id = $_GET['cat_id'];

        $loggeduserid = $_SESSION['loggeduser_id'];



        $sql = " INSERT INTO `threads` (`thread_title`, `thread_desc`,`thread_user_id`,`thread_cat_id` ,`thread_created`) VALUES ('$newthreadtitle', '$newthreaddesc',' $loggeduserid','$cat_id', current_timestamp());";
        $insertthreadresult = $conn->query($sql);

        $threadinsertionalert = true;
        if ($threadinsertionalert == true) {
            echo '
                <div class="alert alert-success alert-dismissible fade show" role="alert">
                <strong>Success!</strong> Your question has been added in this forum. Please check below.
                <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
                </div>
                ';
        }
    }
    ?>







    <!-- 
    <div class="container my-2">
        <div class="alert alert-success" role="alert">
            <h3 class="alert-heading">Welcome , <?php echo $_SESSION['loggeduser']; ?></h3>
            <p class="my-0">You have successfully logged in. </p>

        </div>
    </div> -->

    <!-- jumbotron -->
    <div class="container my-3 d-flex justify-content-center">
        <div class="col-md-12 ">

            <div class="h-100 p-5 text-white bg-dark rounded-3">
                <h2 style="font-family: Verdana, Geneva, Tahoma, sans-serif">
                    Welcome to <?php echo $catname; ?> forums</h2>
                <p><?php echo $catdesc; ?></p>
                <hr>
                <p class="flex-shrink-0 p-0 m-0 ">

                <ul class="text-danger list-unstyled">
                    <li> Keep it friendly.</li>
                    <li>Be courteous and respectful. Appreciate that others may have an opinion different from yours.
                    </li>
                    <li> Stay on topic.</li>
                    <li>Share your knowledge.</li>
                    <li>Refrain from demeaning, discriminatory, or harassing behaviour and speech.</li>
                </ul>
                </p>
                <?php
                if ($loggedin == true) {
                    echo '
                     <button class="btn btn-lg btn-outline-light" type="button" data-bs-toggle="modal" data-bs-target="#askquestionmodal">Ask a Question</button>
                    
                    ';
                } else {
                    echo '
                    <button type="button" class="btn btn-success mx-1" data-bs-toggle="modal" data-bs-target="#loginmodal">
                Login to ask a question
            </button>
                    ';
                }
                ?>




            </div>
        </div>
    </div>
    <!-- jumbotron -->



    <div class="container" style="min-height: 300px;">
        <h2>Browse Questions</h2>

        <!-- list starts -->
        <?php
        $sql = "SELECT * FROM `threads` WHERE `thread_cat_id`=$cat_id";
        $result = $conn->query($sql);
        echo '
        <div class="d-flex flex-column my-3  p-2 " style="background-color:whitesmoke; border: 0.3px solid lightgray;">
        ';
        if ($result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) {
                $thread_user_id = $row['thread_user_id'];
                $sql2 = "SELECT * FROM `users` WHERE `user_id`=$thread_user_id";
                $result2 = $conn->query($sql2);
                $threaduser = $result2->fetch_assoc();

                echo '
            <div class="container d-flex flex-row m-2 p-2">
                <div class="flex-shrink-0 ">
                    <div class="flex-shrink-0 d-flex flex-column p-1 align-items-center" style="max-width:80px;">
                                <img src="/myapp/myforum/img/defaultuser.png" style="width:60px" alt=" defaultuser.png">
                               <small>Asked by</small> <small style="font-style:italic; color: blue; text-align:center;" >' . $threaduser['username'] . '</small>
    
                    </div>
                </div>
                <div class="flex-row-reverse w-100">
                    <div class="d-flex  justify-content-between mx-3">
                    <h5> <a  style="text-decoration:none" href="thread.php?thread_id=' . $row['thread_id'] . '">
                            ' . $row['thread_title'] . '
                        </a></h5>
                        <small>' . $row['thread_created'] . '</small>
                    </div>

                    <div class="flex-grow-1 ms-3">
                        ' . substr($row['thread_desc'], 0, 250) . ' . . . 
                    </div>
                </div>
                
            </div>
        
        
        ';
            }
        } else {
            echo '
            <div class="container p-3 d-flex justify-content-center">
                No threads has been found. Be the first person to start one.
            </div>
            
            ';
        }
        echo '</div>';
        ?>
        <!-- list ends -->


    </div>
    <?php include 'partials/_askquestionmodal.php'; ?>

    <?php
    require 'partials/_footer.php';
    ?> <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-kenU1KFdBIe4zVF0s0G1M5b4hcpxyD9F7jL+jjXkk+Q2h455rYXK/7HAuoJl+0I4" crossorigin="anonymous">
    </script>
</body>

</html>