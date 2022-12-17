@extends('layouts.instructorlayout')
@section('content')

<center>
<h3>Create Topic</h3>

<form  class="form-floating " style="width:800px;  border:0px solid rgb(156, 155, 155); text-align:left; padding:40px 40px 40px 40px;  background-color:rgb(240, 240, 240)" action="{{route('instructor.createtopicsubmit')}}" method="post" enctype="multipart/form-data">
    {{@csrf_field()}}
    <div class="form-floating">
       
        <input class="form-control" type="text" name="t_number" value="{{$lastnumber+1}}" readonly>
        <label for = "t_number">Topic Number: </label> 
        <br>
    </div>

        <div class="form-floating">
        
         <input class="form-control" type="text" name="t_title" value="{{old('t_title')}}" placeholder="Enter a title">
         <label for = "t_title">Topic Title: </label>
         @error('t_title')
        <span>{{$message}}</span>
        @enderror
        <br>
    </div>

     <div class="form-floating">
        <fieldset >
            <label style="float: left" for = "t_video">Lecture video: </label>
         <input  class="form-control" type="file" name="t_video">
        
        @error('t_video') 
        <span>{{$message}}</span>
        @enderror 
        
        </fieldset>
        <br>
    </div>

        <div class="form-floating" >
       
        <textarea style="martin-top:20px; height:300px;" class="form-control" name="t_material" placeholder="Provide Study Material" rows="10" cols="50">{{old('t_material')}}</textarea>
        <label for = "t_video">Lecture Material: </label>
        @error('t_material')
        <span>{{$message}}</span>
        @enderror
        <br>
        </div>
    

        <input class="btn btn-secondary" type="submit" value="Create">
    </form>

</center>
@endsection