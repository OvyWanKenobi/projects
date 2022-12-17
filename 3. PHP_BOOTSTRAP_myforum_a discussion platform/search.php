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


    <div id="maincontainer" style="min-height:80vh;">


        <div class="container my-4">
            <h2> Search result for "<em><?php echo $_GET['search']; ?></em>" </h2>
            <hr>
            <div>
                <?php
                $sql = "SELECT * FROM  `threads` WHERE MATCH (`thread_title`, `thread_desc`) AGAINST ('" . $_GET['search'] . "')";
                $result = $conn->query($sql);
                if ($result->num_rows > 0) {
                    while ($row = $result->fetch_assoc()) {
                        $threadtitle = $row['thread_title'];
                        $threaddesc = $row['thread_desc'];
                        $thread_id = $row['thread_id'];
                        echo '
                        <h4><a href="thread.php?thread_id= ' . $thread_id . '">' . $threadtitle . '</a></h4>
                        <p>' . $threaddesc . '</p>
                        ';
                    }
                } else {
                    echo '
                     
                        <div class="container p-4 d-flex flex-column justify-content-center" style="background-color:whitesmoke;">
                             <h5 class="display-6">Upps! No results found.</h5>
                            <p class="lead">
                             Suggestions:
                                <li>Make sure that all words are spelled correctly.</li>
                                <li>Try different keywords.</li>
                                <li>Try more general keywords.</li>
                             </p>
                        </div>
                        
                       
                    ';
                }
                ?>

            </div>
        </div>


    </div>
    <?php
    require 'partials/_footer.php';
    ?>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-kenU1KFdBIe4zVF0s0G1M5b4hcpxyD9F7jL+jjXkk+Q2h455rYXK/7HAuoJl+0I4" crossorigin="anonymous">
    </script>
</body>

</html>