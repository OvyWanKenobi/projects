@extends('layouts.instructorlayout')
@section('content')

<br>
<center>
    <div style="width:1000px;  border:0px solid rgb(156, 155, 155); text-align:left; padding:15px 40px 15px 40px; background-color:rgb(240, 240, 240)">
@if (($course->c_thumbnail)==Null)
<img  src="{{asset('storage/noimage.png')}}"  style="width:200px; height:200px; object-fit:cover;"  alt="Image">
@else
<img  src="{{asset('storage/coursethumbnail/'.$course->c_thumbnail)}}"  style="width:200px; height:200px; object-fit:cover;"  alt="Image">
@endif

<h3> Title: {{$course->c_title}}</h3>
<h4> Description: {{$course->c_description}}</h4> 
<h4> Price: {{$course->c_price}}</h4> 
<h4> Rating: 
    @php
    $rat=0;
    $totrat=count($course->studentsincourse);
    @endphp
    @foreach($course->ratingsofcourse as $cr)
    @php
        $rat=$rat + ($cr->r_rating)  ;
    @endphp
    
    @endforeach
    @if(count($course->ratingsofcourse) == 0)
    Not Rated
    @else
    {{$rat/$totrat}} /5  ({{$totrat}})</h4>
    @endif
    
<h4> Status: {{$course->c_status}}</h4> 


<div
    @if(count($course->studentsincourse) != 0) 
    class="clickable  " style="cursor:pointer; "  onclick="window.location='{{route('instructor.coursestudentlist',['cid'=>encrypt($course->id)])}}'"
    @endif
    >
   
    <h2 class="btn btn-outline-primary" style="font-size: 20;">Total Enrollments: {{count($course->studentsincourse)}}</h2>

</div>

<a class="btn btn-success" href="{{route('instructor.editcourse',['courseid'=>encrypt($course->id)])}}">Edit Course</a>

{{-- <a class="btn btn-danger" href="{{route('instructor.deletecourse',['courseid'=>encrypt($course->id)])}}">Delete Course</a> --}}

</div>
<br>
<div style="width:1000px;  border:0px solid rgb(180, 180, 180); text-align:left; padding:15px 40px 15px 40px; background-color:rgb(240, 240, 240)">

<h4>Course Topics  <a class="btn btn-secondary" href="{{route('instructor.createtopic',['courseid'=>encrypt($course->id)])}}">Create Topic</a></h4>

@if(count($course->topics)>0)

<table class="table  table-hover">
  

  @foreach($course->topics as $t)

      <tr class="clickable  " style="cursor:pointer; "  onclick="window.location='{{route('instructor.viewtopic',['id'=>encrypt($t->id)])}}'">

          <td> {{$t->t_number}}</td>
          <td> {{$t->t_title}}</td>
 
  @endforeach
</table>

@else
<h5><span class="label label-warning" >No data found</span></h5>
@endif
</div>
</center>
@endsection