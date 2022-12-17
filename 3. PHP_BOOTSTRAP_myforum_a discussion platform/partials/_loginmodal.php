<!-- Modal -->
<div class="modal fade" id="loginmodal" tabindex="-1" aria-labelledby="loginmodal" aria-hidden="true">
    <div class="modal-dialog modal-dialog-centered">
        <div class="modal-content">
            <div class="modal-header bg-dark text-light">
                <h1 class="modal-title fs-5 text-center" id="loginmodal">LOGIN </h1>
                <button type="button" class="btn-close btn-close-white" data-bs-dismiss="modal" aria-label="Close"></button>
            </div>
            <div class="modal-body mb-3 ">
                <form action="/myapp/myforum/partials/_handlelogin.php" method="post" class="d-flex flex-column align-items-center my-3">
                    <div class=" mb-3  col-8">
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

        </div>
    </div>
</div>