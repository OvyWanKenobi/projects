@extends('layouts.instructorlayout')
@section('content')

<center>
    <h2 style="color:rgb(0, 122, 179); padding:10px; font-family:">Welcome, {{$instructor->ins_name}}</h2>


    <div style="width:1200px;  border:0px solid rgb(156, 155, 155); text-align:left; padding:15px 40px 15px 40px; background-color:rgb(240, 240, 240)">
<h3 style="text-align: left; padding:15px;">My courses :</h3>
@if(count($instructor->coursesbyinstructor)>0)

<table class="table  table-hover" >
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

      <tr class="clickable  " style="cursor:pointer; "  onclick="window.location='{{route('instructor.viewcourse',['id'=>encrypt($c->id)])}}'">

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


</div>
</center>
@endsection