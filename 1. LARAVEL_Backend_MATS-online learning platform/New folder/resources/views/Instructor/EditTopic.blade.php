@extends('layouts.instructorlayout')
@section('content')

<center>
<h3>Edit Topic</h3>

<form class="form-floating " style="width:800px;  border:0px solid rgb(156, 155, 155); text-align:left; padding:40px 40px 40px 40px; background-color:rgb(240, 240, 240)" action="{{route('instructor.edittopicsubmit')}}" method="post" enctype="multipart/form-data">
     {{@csrf_field()}}
     <div class="form-floating">
        
        <input  class="form-control" type="text" name="t_number" value="{{$topic->t_number}}" readonly >
        <label for = "t_number">Topic Number: </label> 
        <br>
    </div>
        <div class="form-floating">
        
         <input class="form-control"  type="text" name="t_title" value="{{ (old('t_title')!==null) ? old('t_title') : $topic->t_title }}" placeholder="Enter a title">
         <label for = "t_title">Topic Title: </label>
         @error('t_title')
        <span>{{$message}}</span>
        @enderror
        <br>
    </div>

        <div class="form-floating">
            <fieldset>
            <label style="float: left" for = "t_video">Lecture video: </label>
         <input  class="form-control" type="file" name="t_video" value="{{ (old('t_video')!==null) ? old('t_video') : $topic->t_video }}">
      
         @error('t_video') 
        <span>{{$message}}</span>
        @enderror 
    </fieldset>
        <br>
    </div>
        <div class="form-floating">
       
        <textarea class="form-control"  style="height: 300px;"  name="t_material" placeholder="Provide Study Material" rows="10" cols="50">{{ (old('t_material')!==null) ? old('t_material') : $topic->t_material }}</textarea>
        <label  for = "t_material"> Lecture material: </label> 
        @error('t_material')
        <span>{{$message}}</span>
        @enderror
       
        <br>
    </div>
    

        <input class="btn btn-secondary" type="submit" value="Update">
    </form>

</center>
@endsection