@extends('layouts.publiclayout')
@section('content')
    <h1>Instructor {{$instructor->id}} Details</h1>

    <br><br>
    <h3>Teacher's Details</h3>
         @if (($instructor->ins_dp)==Null)
        <img id="dpicon" src="{{asset('storage/nodpimage.png')}}"  style="width:150px; height:150px;"  alt="Image">
        @else
        <img id="dpicon" src="{{asset('storage/dp/instructors/'.$instructor->ins_dp)}}"  style="width:150px; height:150px; border-radius:50%; "  alt="Image">
        @endif
    <h4> Name: {{$instructor->ins_name}}</h4>
    <h4> Degree: {{$instructor->ins_degree}}</h4> 
    <h4> Bio: {{$instructor->ins_bio}}</h4> 
    <h4> Category: {{$instructor->instructorcategory->cat_name}}</h4> 
    <h4> Phone: {{$instructor->ins_phone}}</h4> 
    <h4> Email: {{$instructor->ins_email}}</h4> 
    <h4> Experience: {{$instructor->ins_exp}}</h4> 
     <h4>Courses by Instructor: </h4> 

     @if(count($instructor->coursesbyinstructor)>0)
     <table class="table  table-hover">
        <tr>
            <th>Image </th>
      
            <th>Course Title</th>
            <th>Course Description</th>
            <th>Course Price</th>
            <th>Enrollments count</th>
            <th>Rating</th>
            <th>Course Status</th>
      
        </tr>
      
        @foreach($instructor->coursesbyinstructor as $c)
      
            <tr class="clickable  " style="cursor:pointer; "  onclick="window.location='#'">
      
              <td >
                  @if (($c->c_thumbnail)==Null)
                  <img  src="{{asset('storage/noimage.png')}}"  style="width:100px; height:100px;"  alt="Image">
                  @else
                  <img  src="{{asset('storage/coursethumbnail/'.$c->c_thumbnail)}}"  style="width:100px; height:100px; "  alt="Image">
                  @endif
              </td>
      
                <td> {{$c->c_title}}</td>
                <td> {{$c->c_description}}</td>
                <td> {{$c->c_price}}</td>
                <td>
                  {{count($c->studentsincourse)}}
               </td>
               <td>
                   @php
                      $rat=0;
                      $totrat=count($c->studentsincourse);
                  @endphp
                  @foreach($c->ratingsofcourse as $cr)
                      @php
                          $rat=$rat + ($cr->r_rating)  ;
                      @endphp
                      
                  @endforeach
                  
                  @if(count($c->ratingsofcourse) == 0)
                  Not Rated
                  @else
                  {{$rat/$totrat}} /5  ({{$totrat}})</h4>
                  @endif
                  
               </td>
      
               <td> {{$c->c_status}}</td>
            </tr>
        @endforeach
      </table>

      @else
    <h5><span class="label label-warning" >No data found</span></h5>
    @endif
@endsection