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

    <div class="maincontainer" style="min-height: 80vh;">



        <?php
        $thread_id = $_GET['thread_id'];
        $sql = "SELECT * FROM  `threads` WHERE `thread_id`=$thread_id";
        $result = $conn->query($sql);
        if ($result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) {

                $threadtitle = $row['thread_title'];
                $threaddesc = $row['thread_desc'];
                $threadcreated = $row['thread_created'];
                $thread_user_id = $row['thread_user_id'];
                $sql2 = "SELECT * FROM `users` WHERE `user_id`=$thread_user_id";
                $result2 = $conn->query($sql2);
                $threaduser = $result2->fetch_assoc();
            }
        }


        ?>


        <!-- jumbotron -->
        <div class="container my-3 d-flex justify-content-center">
            <div class="col-md-12">

                <!-- upper question starts -->
                <div class="p-5 text-white bg-dark " style=" border-radius: 25px 25px 0px 0px;">
                    <h2 style="font-family: Verdana, Geneva, Tahoma, sans-serif">
                        <?php echo $threadtitle; ?></h2>
                    <b style=" font-style: italic;"> <?php echo 'Asked by ' . $threaduser['username'] . ' on ' .  $threadcreated; ?></b>

                    <p class="p-2 m-0"><?php echo $threaddesc; ?></p>

                    <!-- <button class="btn btn-lg btn-outline-light" type="button">Ask A Question</button> -->
                </div>
                <!-- upper question ends -->


                <div class="p-md-5 pt-md-4 text-dark p-4" style=" border-radius: 0px 0px 25px 25px; border: 0.5px solid darkgrey; background-color: whitesmoke ;">
                    <!-- ask question form starts -->

                    <?php

                    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
                        $newanswer = $_POST['answer'];
                        $newanswer = str_replace("<", "&lt;", $newanswer); //sanitize, xss attack prevention, if someone use <tag> in inputs 
                        $newanswer = str_replace(">", "&gt;", $newanswer); //sanitize, xss attack prevention, if someone use <tag> in inputs

                        $thread_id = $_GET['thread_id'];

                        $loggeduserid = $_SESSION['loggeduser_id'];

                        $sql = " INSERT INTO `answers` (`ans_answer`, `ans_thread_id`,`ans_user_id`,`ans_created`) VALUES ('$newanswer', '$thread_id','$loggeduserid ', current_timestamp());";
                        $insertanswerresult = $conn->query($sql);
                    }


                    ?>



                    <?php
                    if ($loggedin == true) {

                        echo '
                     <div class="mb-3">
                        <form action="' . $_SERVER['REQUEST_URI'] . '" method="post" class="d-flex flex-column ">

                            <div class="mb-3 col-md-12 col-8">
                                <label for="answer" class="form-label">Write your Answer</label>
                                <textarea class="form-control" id="answer" name="answer" rows="3"></textarea>
                            </div>

                            <button type="submit" class="btn btn-dark col-md-2 col-8">Submit Answer</button>
                        </form>
                    </div>
                    
                    ';
                    } else {
                        echo '
                    <button type="button" class="btn btn-success mx-1" data-bs-toggle="modal" data-bs-target="#loginmodal">
                Login to Answer this Question
            </button>
                    ';
                    }
                    ?>


                    <!-- ask question form ends -->

                    <hr>

                    <h4>Discussion</h4>


                    <?php
                    $sql = "SELECT * FROM `answers` WHERE `ans_thread_id`='$thread_id' ";
                    $result = $conn->query($sql);

                    if ($result->num_rows > 0) {
                        while ($row = $result->fetch_assoc()) {
                            $ans_user_id = $row['ans_user_id'];
                            $sql2 = "SELECT * FROM `users` WHERE `user_id`='$ans_user_id'";
                            $result2 = $conn->query($sql2);
                            $answeruser = $result2->fetch_assoc();
                            echo '
                        <div class="container d-flex flex-row m-md-2 p-2 ">
                            <div class="flex-shrink-0 d-flex flex-column p-1 align-items-center" style="max-width:80px;">
                                <img src="/myapp/myforum/img/defaultuser.png" style="width:50px" alt=" defaultuser.png">
                                <small>' . $answeruser["username"] . '</small>
                                 <small>' . $row['ans_created'] . '</small>
                            </div>
                            <div class="flex-row-reverse w-100">
                                <div class="d-flex  justify-content-between mx-3">
                                <h5>  ' . $row['ans_answer'] . '
                                    </h5>
                                
                                </div>

                                
                            </div>
                            
                        </div>
                    
                    
                    ';
                        }
                    } else {
                        echo '
                        <div class="container p-3 d-flex justify-content-center">
                             Upps! No one answered this problem yet. Be the first to answer.
                        </div>
                        
                        ';
                    }
                    echo '</div>';
                    ?>

                </div>
            </div>
        </div>
        <!-- jumbotron -->

    </div> <!-- main container div-->




    <?php
    require 'partials/_footer.php';
    ?>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-kenU1KFdBIe4zVF0s0G1M5b4hcpxyD9F7jL+jjXkk+Q2h455rYXK/7HAuoJl+0I4" crossorigin="anonymous">
    </script>
</body>

</html>