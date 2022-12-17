<!-- Modal -->
<div class="modal fade" id="signupmodal" tabindex="-1" aria-labelledby="signupmodal" aria-hidden="true">
    <div class="modal-dialog modal-dialog-centered">
        <div class="modal-content">
            <div class="modal-header bg-dark text-light">
                <h1 class="modal-title fs-5 text-center" id="signupmodal">SIGNUP</h1>
                <button type="button" class=" btn-close btn-close-white" data-bs-dismiss="modal" aria-label="Close"></button>
            </div>
            <div class="modal-body mb-3">
                <form action="/myapp/myforum/partials/_handlesignup.php" method="post" class="d-flex flex-column align-items-center ">
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

        </div>
    </div>
</div>