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


    <!-- 
    <div class="container my-2">
        <div class="alert alert-success" role="alert">
            <h3 class="alert-heading">Welcome , <?php echo $_SESSION['loggeduser']; ?></h3>
            <p class="my-0">You have successfully logged in. </p>

        </div>
    </div> -->

    <!-- carousal slider start -->
    <?php
    if (!$loggedin) {
        echo '
 <div class="container-fluid mx-0 px-0">
        <div id="carouselExampleCaptions" class="carousel slide" data-bs-ride="false">
            <div class="carousel-indicators">
                <button type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide-to="0" class="active" aria-current="true" aria-label="Slide 1"></button>
                <button type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide-to="1" aria-label="Slide 2"></button>
                <button type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide-to="2" aria-label="Slide 3"></button>
            </div>
            <div class="carousel-inner">
                <div class="carousel-item active">
                    <img src="http://source.unsplash.com/1350x300/?coding, programming, javascript" class="d-block w-100" alt="...">
                    <div class="carousel-caption d-none d-md-block">
                        <h5>First slide label</h5>
                        <p>Some representative placeholder content for the first slide.</p>
                    </div>
                </div>
                <div class="carousel-item">
                    <img src="http://source.unsplash.com/1350x300/?coding, programming, python" class="d-block w-100" alt="...">
                    <div class="carousel-caption d-none d-md-block">
                        <h5>Second slide label</h5>
                        <p>Some representative placeholder content for the second slide.</p>
                    </div>
                </div>
                <div class="carousel-item">
                    <img src="http://source.unsplash.com/1350x300/?programming, c++" class="d-block w-100" alt="...">
                    <div class="carousel-caption d-none d-md-block">
                        <h5>Third slide label</h5>
                        <p>Some representative placeholder content for the third slide.</p>
                    </div>
                </div>
            </div>
            <button class="carousel-control-prev" type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide="prev">
                <span class="carousel-control-prev-icon" aria-hidden="true"></span>
                <span class="visually-hidden">Previous</span>
            </button>
            <button class="carousel-control-next" type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide="next">
                <span class="carousel-control-next-icon" aria-hidden="true"></span>
                <span class="visually-hidden">Next</span>
            </button>
        </div>
    </div>
        ';
    }


    ?>

    <!-- carousal slider end -->


    <!-- catagory container starts -->
    <div class="container my-4" style="min-height:400px;">
        <h3 class="text-center">myForum - Catagories</h3>
        <div class="row">

            <!-- forloop thru catagories -->

            <?php
            $sql = "SELECT * FROM `catagories`";
            $result = $conn->query($sql);
            if ($result->num_rows > 0) {
                while ($row = $result->fetch_assoc()) {
                    echo '
                    <div class="col-md-3 my-2">
                        <div class="card">
                            <div class="card-body">
                                <h5 class="card-title">' . $row['cat_title'] . '</h5>
                                <p class="card-text" style="min-height:14vh; ">' . substr($row['cat_desc'], 0, 100) . ' ....</p>
                                <a href="threadlist.php?cat_id=' . $row['cat_id'] . '" class="btn btn-primary">View Threads</a>
                            </div>
                        </div>
                    </div>
                    
                    ';
                }
            }


            ?>




            <!-- forloop thru catagories -->

        </div>
    </div>

    <!-- catagory container starts -->

    <?php
    require 'partials/_footer.php';
    ?>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-kenU1KFdBIe4zVF0s0G1M5b4hcpxyD9F7jL+jjXkk+Q2h455rYXK/7HAuoJl+0I4" crossorigin="anonymous">
    </script>
</body>

</html>