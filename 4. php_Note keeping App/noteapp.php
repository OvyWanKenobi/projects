<?php
//connect to DB
$sernamename = "localhost";
$username = "root";
$password = "";
$database = "db2";

// $conn = mysqli_connect($sernamename, $username, $password);

//create connection
try {
    $conn = new mysqli($sernamename, $username, $password, $database);
    //echo "Successful Connection to DB";
} catch (Exception $e) {
    echo "Connection failed to DB" . $e->getMessage();
}

$insertion = false;
$updation = false;
$deletation = false;


if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['slnoedit'])) {

        //if slno already set update
        $title = $_POST["edittitle"];
        $note = $_POST["editnote"];
        $sl = $_POST['slnoedit'];

        $sql = "UPDATE `notes` SET `note` = '$note' , `title` = '$title' , `lastmodified` = current_timestamp() WHERE `notes`.`id` = $sl;";
        $updateresult = $conn->query($sql);
        if ($updateresult === TRUE) {
            // echo "New note created successfully";
            $updation = true;
        } else {
            $updation = false;
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
    } elseif (isset($_POST['slnodelete'])) {
        //if slno already set update

        $sl = $_POST['slnodelete'];

        $sql = "DELETE FROM `notes` WHERE `notes`.`id` = $sl";
        $deleteresult = $conn->query($sql);
        if ($deleteresult === TRUE) {
            // echo "New note created successfully";
            $deletation = true;
        } else {
            $deletation = false;
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
    } else {

        //else insert
        $title = $_POST["title"];
        $note = $_POST["note"];

        $sql = "INSERT INTO `notes` (`title`, `note`, `lastmodified`) VALUES ('$title', '$note', current_timestamp());";
        $insertresult = $conn->query($sql);
        // global $insert = true;

        if ($insertresult === TRUE) {
            // echo "New note created successfully";
            $insertion = true;
        } else {
            $insertion = false;
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
    }
}

?>


<!doctype html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>NoteApp</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65" crossorigin="anonymous">
    <link href="https://cdn.datatables.net/1.13.1/css/jquery.dataTables.min.css" rel="stylesheet">



</head>

<body>
    <!-- edit trigger modal -->
    <!-- <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#editModal">
        Edit Note Model
    </button> -->

    <!-- edit Modal -->
    <div class="modal fade" id="editModal" tabindex="-1" aria-labelledby="editModalLabel" aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header bg-warning font-weight-bold">
                    <h1 class="modal-title fs-5" id="editModalLabel">Edit Your Note</h1>
                    <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                </div>
                <div class="modal-body">
                    <div class="container mt-2 mb-4">
                        <form action="/myapp/pp/noteapp.php?" method="POST">
                            <input type="hidden" name="slnoedit" id="slnoedit">
                            <div class="mb-3">
                                <label for="edittitle" class="form-label">Edit Title</label>
                                <input type="text" class="form-control" id="edittitle" name="edittitle" aria-describedby="edittitle">
                            </div>
                            <div class="mb-3">
                                <label for="editnote" class="form-label">Edit Note </label>
                                <textarea class="form-control" id="editnote" name="editnote" rows="5"></textarea>
                            </div>

                            <button type="submit" class="btn btn-warning">Update </button>
                        </form>
                    </div>

                </div>

            </div>
        </div>
    </div>

    <!-- delete Modal -->
    <div class="modal fade" id="deleteModal" tabindex="-1" aria-labelledby="deleteModalLabel" aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header bg-danger text-white font-weight-bold">
                    <h1 class="modal-title fs-5" id="deleteModalLabel">Delete Note</h1>
                    <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                </div>
                <div class="modal-body">
                    <div class="container mt-2 mb-4">
                        <form action="/myapp/pp/noteapp.php?" method="POST">
                            <input type="hidden" name="slnodelete" id="slnodelete">

                            <h2>Are you sure you want to delete this note?</h2>

                            <button type="submit" class="btn btn-danger my-2">Confirm Delete</button>
                        </form>
                    </div>
                </div>

            </div>
        </div>
    </div>

    <!-- Modal -->


    <!-- navbar  -->
    <nav class="navbar navbar-expand-lg bg-dark navbar-dark sticky-top">
        <div class="container-fluid">
            <a class="navbar-brand" href="/myapp/pp/noteapp.php">NoteApp</a>
            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarSupportedContent">
                <ul class="navbar-nav me-auto mb-2 mb-lg-0">
                    <li class="nav-item">
                        <a class="nav-link active" aria-current="page" href="#">Home</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="#">About</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link">Contact Us</a>
                    </li>
                </ul>
                <form class="d-flex" role="search">
                    <input class="form-control me-2" type="search" placeholder="Search" aria-label="Search">
                    <button class="btn btn-outline-success" type="submit">Search</button>
                </form>
            </div>
        </div>
    </nav>

    <?php
    if ($insertion) {
        echo ' <div class="alert alert-success alert-dismissible fade show" role="alert">
            <strong>Success! New note created successfully!
            <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button></strong>
        </div>';
    }
    if ($updation) {
        echo ' <div class="alert alert-success alert-dismissible fade show" role="alert">
            <strong>Success! Note updated successfully!
            <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button></strong>
        </div>';
    }
    if ($deletation) {
        echo ' <div class="alert alert-success alert-dismissible fade show" role="alert">
            <strong>Success! Note Deleted successfully!
            <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button></strong>
        </div>';
    }


    ?>



    <!-- form  -->

    <div class="container my-4">
        <h2>Add Your Note </h2>
        <form action="/myapp/pp/noteapp.php" method="POST">
            <div class="mb-3">
                <label for="title" class="form-label">Title</label>
                <input type="text" class="form-control" id="title" name="title" aria-describedby="title">
            </div>
            <div class="mb-3">
                <label for="note" class="form-label">Note </label>
                <textarea class="form-control" id="note" name="note" rows="5"></textarea>
            </div>

            <button type="submit" class="btn btn-warning">Add Note</button>
        </form>
    </div>
    <!-- form  -->

    <div class="container my-4">

        <table class="table table-responsive" id="myTable">
            <thead>
                <tr>
                    <th scope="col">Sl.No</th>
                    <th scope="col">Title</th>
                    <th scope="col">Note</th>
                    <th scope="col">Last Modified</th>
                    <th scope="col">Actions</th>
                </tr>
            </thead>
            <tbody>
                <?php
                $sql = "SELECT * FROM `notes`";
                $result = $conn->query($sql);
                if ($result->num_rows > 0) {
                    // output data of each row
                    $slno = 0;
                    while ($row = $result->fetch_assoc()) {
                        $slno++;
                        echo "<tr>
                            <th scope='row'>" . $slno . "</th>
                            <td>" . $row["title"] . "</td>
                            <td style='width:30vw;'>" . $row["note"] . "</td>
                            <td>" . $row["lastmodified"] . "</td>
                            <td>  <button type='button' class= 'edit btn btn-primary btn-sm' id=" . $row["id"] . " data-bs-toggle='modal' data-bs-target='#editModal'>Edit</button>
                            <button type='button' class= 'delete btn btn-danger btn-sm' id=" . $row["id"] . " data-bs-toggle='modal' data-bs-target='#deleteModal'>Delete</button>
                            </td>
                            </tr>";
                    }
                    // <a class= 'btn btn-primary btn-sm' href='/edit' role='button'>Edit</a>
                    // <a class= 'btn btn-danger btn-sm' href='/delete' role='button'>Delete</a>
                } else {
                    echo "No Entries Found. [0 Notes]";
                }
                ?>


            </tbody>
        </table>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-kenU1KFdBIe4zVF0s0G1M5b4hcpxyD9F7jL+jjXkk+Q2h455rYXK/7HAuoJl+0I4" crossorigin="anonymous"></script>

    <script src="https://code.jquery.com/jquery-3.6.1.js" integrity="sha256-3zlB5s2uwoUzrXK3BT7AX3FyvojsraNFxCc2vC/7pNI=" crossorigin="anonymous"></script>
    <script src="https://cdn.datatables.net/1.13.1/js/jquery.dataTables.min.js"></script>

    <script>
        $(document).ready(function() {
            $('#myTable').DataTable();
        });
    </script>

    <script>
        edits = document.getElementsByClassName('edit');
        Array.from(edits).forEach((element) => {
            element.addEventListener("click", (e) => {
                console.log("edit", );
                tr = e.target.parentNode.parentNode;
                title = tr.getElementsByTagName("td")[0].innerText;
                note = tr.getElementsByTagName("td")[1].innerText;
                lastmodified = tr.getElementsByTagName("td")[2].innerText;
                console.log(title, note, lastmodified);
                edittitle.value = title;
                editnote.value = note;
                slnoedit.value = e.target.id;
                console.log(e.target.id);

            })
        })

        deletes = document.getElementsByClassName('delete');
        Array.from(deletes).forEach((element) => {
            element.addEventListener("click", (e) => {
                console.log("delete", );
                tr = e.target.parentNode.parentNode;
                // title = tr.getElementsByTagName("td")[0].innerText;
                // note = tr.getElementsByTagName("td")[1].innerText;
                // lastmodified = tr.getElementsByTagName("td")[2].innerText;
                // console.log(title, note, lastmodified);
                // edittitle.value = title;
                // editnote.value = note;
                slnodelete.value = e.target.id;
                console.log(e.target.id);

            })
        })
    </script>

</body>

</html>