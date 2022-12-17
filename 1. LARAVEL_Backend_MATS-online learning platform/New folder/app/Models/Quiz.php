<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Quiz extends Model
{
    use HasFactory;

    protected $table = 'quizzes';
    public $timestamps = false;

    public function quizoftopic(){
        return $this->belongsTo(Topic::class,'q_topic_fk');
    }
}
