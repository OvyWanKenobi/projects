<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Forum extends Model
{
    use HasFactory;
    protected $table = 'forums';
    public $timestamps = false;

    public function course(){
        return $this->belongsTo(Course::class, 'c_id');
    }

    public function users(){
        return $this->belongsTo(Users::class, 'st_id');
    }

    public function forumcomments(){
        return $this->hasMany(Forumcomments::class, 'fc_forum_fk');
    }
}
