<!-- Modal -->
<div class="modal fade" id="askquestionmodal" tabindex="-1" aria-labelledby="askquestionmodal" aria-hidden="true">
    <div class="modal-dialog modal-dialog-centered">
        <div class="modal-content">
            <div class="modal-header">
                <h1 class="modal-title fs-5 text-center" id="askquestionmodal">Start a Problem Discussion </h1>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
            </div>
            <div class="modal-body mb-3">
                <form action="<?php echo $_SERVER['REQUEST_URI']; ?>" method="post" class="d-flex flex-column align-items-center">

                    <div class=" mb-3 col-md-10 col-8 ">
                        <label for=" threadtitle" class="form-label">Problem Title</label>
                        <input type="text" class="form-control" id="threadtitle" name="threadtitle">
                    </div>
                    <div class="mb-3 col-md-10 col-8">
                        <label for="threaddesc" class="form-label">Ellaborate your concern with us</label>
                        <textarea class="form-control" id="threaddesc" name="threaddesc" rows="5"></textarea>
                    </div>

                    <button type="submit" class="btn btn-dark col-md-10 col-8">Submit</button>
                </form>

            </div>

        </div>
    </div>
</div>