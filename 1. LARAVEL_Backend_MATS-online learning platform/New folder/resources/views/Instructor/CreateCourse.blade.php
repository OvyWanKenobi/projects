@extends('layouts.instructorlayout')
@section('content')

<center>
<h3 style="color: rgb(26, 24, 24)">Create Course</h3>



<form class="form-floating " style="width:800px;  border:0px solid rgb(156, 155, 155); text-align:left; padding:40px 40px 40px 40px;  background-color:rgb(240, 240, 240)" action="{{route('instructor.createcoursesubmit')}}" method="post" enctype="multipart/form-data">
    {{@csrf_field()}}
    <div class="form-floating">
        <input type="text"  class="form-control" name="c_title" id="c_title" value="{{old('c_title')}}" placeholder="Give your course a title">
        <label for="c_title">Course Title </label> 
        @error('c_title')
        <span>{{$message}}</span>
        @enderror
        <br>
    </div>

    <div class="form-floating">
        <textarea name="c_description" style="height: 100px;" class="form-control" id="c_description" placeholder="What is this course about?" rows="3" cols="30">{{old('c_description')}}</textarea>
        <label for = "c_description">Course description </label> 
        @error('c_description')
        <span>{{$message}}</span>
        @enderror
        <br>
    </div>

    <div class="form-floating">
         <input type="text" name="c_price" class="form-control" id="c_price" value="{{old('c_price')}}" placeholder="Price">
         <label for = "c_price">Course Price </label>
        @error('c_price')
        <span>{{$message}}</span>
        @enderror
        <br>
    </div>

    <div class="form-floating">
        <fieldset>
        <label style="float: left" for = "c_thumbnail">Course thumbnail: </label>
         <input type="file" class="form-control"  name="c_thumbnail" id="c_thumbnail">
        
        @error('c_thumbnail') 
        <span>{{$message}}</span>
        @enderror 
        </fieldset>
        <br>
        </div>
        <input class="btn btn-secondary" type="submit" value="Create">
    </form>
</div>
</center>
@endsection
