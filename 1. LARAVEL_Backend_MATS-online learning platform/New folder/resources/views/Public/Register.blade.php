@extends('layouts.publiclayout')
@section('content')
    <h1>Register</h1>

    <form action="{{'registersubmit'}}" method = "POST" enctype="multipart/form-data">
        <div class="form-group mb-3">
            <label>Name</label>
            <input type="text" name="name" class="form-control">
        </div>
        <div class="form-group mb-3">
            <label>Username</label>
            <input type="text" name="ins_username" class="form-control">
        </div>
        <div class="form-group mb-3">
            <label>Degree</label>
            <input type="text" name="ins_degree" class="form-control">
        </div>
        <div class="form-group mb-3">
            <label>Bio</label>
            <input type="text" name="ins_bio" class="form-control">
        </div>
    </form>

@endsection