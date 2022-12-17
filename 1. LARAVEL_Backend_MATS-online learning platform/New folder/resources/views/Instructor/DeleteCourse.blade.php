@extends('layouts.instructorlayout')
@section('content')

<h3>Delete Course</h3>

<br><br>

@if (($course->c_thumbnail)==Null)
<img  src="{{asset('storage/noimage.png')}}"  style="width:100px; height:100px;"  alt="Image">
@else
<img  src="{{asset('storage/coursethumbnail/'.$course->c_thumbnail)}}"  style="width:100px; height:100px; "  alt="Image">
@endif
<h4> Title: {{$course->c_title}}</h4>
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

<h2>Are you sure you want to delete this course </h2>

<a class="btn btn-warning" href="{{route('instructor.viewcourse',['id'=>encrypt($course->id)])}}">No</a>
<a class="btn btn-danger" href="{{route('instructor.deletecoursesubmit',['id'=>encrypt($course->id)])}}">Yes</a>

@endsection